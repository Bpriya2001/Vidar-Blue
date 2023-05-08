#include <zephyr/shell/shell.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/usb/usb_device.h>
#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <stdio.h>
#include <zephyr/sys/util.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>


/*Bluetooth connection flag*/
bool bluetooth = false;
/*BLE_default_connection*/
struct bt_conn *conn;

/*Bluetooth connection advertising data*/
static const struct bt_data ad[] = {
    BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
    BT_DATA_BYTES(BT_DATA_UUID128_ALL,
                  0xd0, 0x92, 0x67, 0x35, 0x78, 0x16, 0x21, 0x91,
                  0x26, 0x49, 0x60, 0xeb, 0x06, 0xa7, 0xca, 0xcb),
};

/*UUID value for AHU */
static struct bt_uuid_128 ahu_uuid = BT_UUID_INIT_128(
    0xd0, 0x92, 0x67, 0x35, 0x78, 0x16, 0x21, 0x91,
    0x26, 0x49, 0x60, 0xeb, 0x06, 0xa7, 0xca, 0xcb);

/*UUID values for ultrasonic sensor*/
static struct bt_uuid_128 ultra_uuid = BT_UUID_INIT_128(
    0xd1, 0x92, 0x67, 0x35, 0x78, 0x16, 0x21, 0x91,
    0x26, 0x49, 0x60, 0xeb, 0x06, 0xa7, 0xca, 0xcb);

/*Buffer containing values for ultrasonic sensor*/
double buf_ultra[2] = {4.0, 5.0};

/** 
* callback function to update values of the ultrasonic sensor
*/
static ssize_t read_ultra(struct bt_conn *conn,
                          const struct bt_gatt_attr *attr, void *buf,
                          uint16_t len, uint16_t offset) {
    const int16_t *value = attr->user_data;

    return bt_gatt_attr_read(conn, attr, buf, len, offset, value,
                             sizeof(buf_ultra));
}

/** 
* GATT service for AHU
*/
BT_GATT_SERVICE_DEFINE(mobile_svc,
                BT_GATT_PRIMARY_SERVICE(&ahu_uuid),

                BT_GATT_CHARACTERISTIC(&ultra_uuid.uuid,
                                        BT_GATT_CHRC_READ,
                                        BT_GATT_PERM_READ,
                                        read_ultra, NULL, &buf_ultra),);

/** 
* Function to enable bluetooth and advertise uuid for connection
*/
static void bt_ready() {
    int err = bt_enable(NULL);
	if (err) {
		printf("Bluetooth init failed (err %d)", err);
		return;
	}
	printf("Bluetooth initialized");
	/* Start advertising */
	err = bt_le_adv_start(BT_LE_ADV_CONN, ad, ARRAY_SIZE(ad), NULL, 0);
	if (err) {
		printf("Advertising failed to start (err %d)", err);
		return;
	}

	printf("Configuration mode: waiting connections...");
}

/** 
* Connection call back function
*/
static void connected(struct bt_conn *connected, uint8_t err) {
	if (err) {
		printf("Connection failed (err %u)", err);
	} else {
		printf("Connected");
		if (!conn) {
			conn = bt_conn_ref(connected);
		}
        bluetooth = true;
	}
    
    printf("connected\n");
}

/** 
* Disconnect callback function
*/
static void disconnected(struct bt_conn *disconn, uint8_t reason) {
	if (conn) {
		bt_conn_unref(conn);
		conn = NULL;
	}

    bluetooth = false;

	printf("Disconnected (reason %u)", reason);
}

/** 
*register connection callback struct
*/
static struct bt_conn_cb conn_callbacks = {
    .connected = connected,
    .disconnected = disconnected,
};

static void process_sample(const struct device *dev)
{
	static unsigned int obs;
	struct sensor_value temp, hum;
	if (sensor_sample_fetch(dev) < 0) {
		printf("Sensor sample update error\n");
		return;
	}

	if (sensor_channel_get(dev, SENSOR_CHAN_AMBIENT_TEMP, &temp) < 0) {
		printf("Cannot read HTS221 temperature channel\n");
		return;
	}

	if (sensor_channel_get(dev, SENSOR_CHAN_HUMIDITY, &hum) < 0) {
		printf("Cannot read HTS221 humidity channel\n");
		return;
	}

	++obs;
	printf("Observation:%u\n", obs);

	/* display temperature */
	printf("Temperature:%.1f C\n", sensor_value_to_double(&temp));
	buf_ultra[0] = sensor_value_to_double(&temp);

	/* display humidity */
	printk("Relative Humidity:%.1f%%\n",
	       sensor_value_to_double(&hum));
	buf_ultra[1] = sensor_value_to_double(&hum);
}

static void hts221_handler(const struct device *dev,
			   const struct sensor_trigger *trig)
{
	process_sample(dev);
}


void main(void) {
	const struct device *const dev = DEVICE_DT_GET_ONE(st_hts221);

	if (!device_is_ready(dev)) {
		printf("sensor: device not ready.\n");
		return;
	}

	if (IS_ENABLED(CONFIG_HTS221_TRIGGER)) {
		struct sensor_trigger trig = {
			.type = SENSOR_TRIG_DATA_READY,
			.chan = SENSOR_CHAN_ALL,
		};
		if (sensor_trigger_set(dev, &trig, hts221_handler) < 0) {
			printf("Cannot configure trigger\n");
			return;
		}
	}

	bt_ready();
    bt_conn_cb_register(&conn_callbacks);

	while (!IS_ENABLED(CONFIG_HTS221_TRIGGER)) {
		//process_sample(dev);
		k_sleep(K_MSEC(2000));
	}

	/**while (1) {
		k_msleep(100);
	}*/
}