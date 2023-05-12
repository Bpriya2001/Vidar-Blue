#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>

#include "ble.h"

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

/*UUID values for ultrasonic sensor*/
static struct bt_uuid_128 gas_uuid = BT_UUID_INIT_128(
    0xd2, 0x92, 0x67, 0x35, 0x78, 0x16, 0x21, 0x91,
    0x26, 0x49, 0x60, 0xeb, 0x06, 0xa7, 0xca, 0xcb);

/*Buffer containing values for ultrasonic sensor*/
uint8_t sensor_buf[5] = {0xAA, 0x04, 0x05, 0x04, 0x05};
//uint16_t co2_tvoc_buf[2] = {5.0, 4.0};

/** 
* callback function to update values of the ultrasonic sensor
*/
static ssize_t read_ultra(struct bt_conn *conn,
                          const struct bt_gatt_attr *attr, void *buf,
                          uint16_t len, uint16_t offset) {
    const int16_t *value = attr->user_data;

    return bt_gatt_attr_read(conn, attr, buf, len, offset, value,
                             sizeof(sensor_buf));
}

/**static ssize_t read_gas_buf(struct bt_conn *conn,
                          const struct bt_gatt_attr *attr, void *buf,
                          uint16_t len, uint16_t offset) {
    const int16_t *value = attr->user_data;

    return bt_gatt_attr_read(conn, attr, buf, len, offset, value,
                             sizeof(co2_tvoc_buf));
}**/

/** 
* GATT service for AHU
*/
BT_GATT_SERVICE_DEFINE(mobile_svc,
                BT_GATT_PRIMARY_SERVICE(&ahu_uuid),

                BT_GATT_CHARACTERISTIC(&ultra_uuid.uuid,
                                        BT_GATT_CHRC_READ,
                                        BT_GATT_PERM_READ,
                                        read_ultra, NULL, &sensor_buf),
                /**BT_GATT_CHARACTERISTIC(&gas_uuid.uuid,
                                        BT_GATT_CHRC_READ,
                                        BT_GATT_PERM_READ,
                                        read_gas_buf, NULL, &co2_tvoc_buf),*/
                                        );

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

void ble_thread_init() {
    bt_ready();
    bt_conn_cb_register(&conn_callbacks);

    while (1) {
		k_msleep(100);
	}
}