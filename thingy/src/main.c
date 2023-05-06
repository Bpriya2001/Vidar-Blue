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

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>

#define AHU_SHELL_THREAD_PRIORITY 1
#define AHU_SHELL_THREAD_STACK 500

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
int16_t buf_ultra[] = {4, 5, 5, 4, 1, 4, 7 , 4};

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
		printk("Bluetooth init failed (err %d)", err);
		return;
	}
	printk("Bluetooth initialized");
	/* Start advertising */
	err = bt_le_adv_start(BT_LE_ADV_CONN, ad, ARRAY_SIZE(ad), NULL, 0);
	if (err) {
		printk("Advertising failed to start (err %d)", err);
		return;
	}

	printk("Configuration mode: waiting connections...");
}

/** 
* Connection call back function
*/
static void connected(struct bt_conn *connected, uint8_t err) {
	if (err) {
		printk("Connection failed (err %u)", err);
	} else {
		printk("Connected");
		if (!conn) {
			conn = bt_conn_ref(connected);
		}
        bluetooth = true;
	}
    
    printk("connected\n");
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

	printk("Disconnected (reason %u)", reason);
}

/** 
*register connection callback struct
*/
static struct bt_conn_cb conn_callbacks = {
    .connected = connected,
    .disconnected = disconnected,
};


void main(void) {
	bt_ready();
    bt_conn_cb_register(&conn_callbacks);

	/*const struct device *const dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_temp));
	//struct sensor_value val;
	//int rc;

	if (!device_is_ready(dev)) {
		printk("Temperature sensor is not ready\n");
		return;
	}

	printk("ESP32 Die temperature sensor test\n");*/

	/**while (1) {
		k_sleep(K_MSEC(300));

		/* fetch sensor samples 
		rc = sensor_sample_fetch(dev);
		if (rc) {
			printk("Failed to fetch sample (%d)\n", rc);
			return;
		}

		rc = sensor_channel_get(dev, SENSOR_CHAN_DIE_TEMP, &val);
		if (rc) {
			printk("Failed to get data (%d)\n", rc);
			return;
		}

		printk("Current temperature: %.1f °C\n", sensor_value_to_double(&val));
	}*/

    while(1) {
        k_msleep(100);
    }
}