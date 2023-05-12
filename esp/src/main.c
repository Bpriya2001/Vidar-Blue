#include <zephyr/types.h>
#include <stddef.h>
#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/sys/byteorder.h>

#define UUID_BUFFER 16
#define THREAD_PRIORITY_READ_BASE -10
#define THREAD_BLE_BASE_STACK 4094
#define THREAD_PRIORITY_BLE_BASE -2

void thread_bsu_ble_init(void);
void thread_ble_read_out(void);
void start_scan(void);
void stop_scan(void);

static struct bt_conn *connection;
bool bluetooth;

/*UUID value for AHU */
uint16_t ahu_uuid[] = {0xd0, 0x92, 0x67, 0x35, 0x78, 0x16, 0x21, 0x91,
                          0x26, 0x49, 0x60, 0xeb, 0x06, 0xa7, 0xca, 0xcb};

/*UUID values for ultrasonic sensor*/
static struct bt_uuid_128 ultra_uuid = BT_UUID_INIT_128(
    0xd1, 0x92, 0x67, 0x35, 0x78, 0x16, 0x21, 0x91,
    0x26, 0x49, 0x60, 0xeb, 0x06, 0xa7, 0xca, 0xcb);

static struct bt_uuid_128 gas_uuid = BT_UUID_INIT_128(
    0xd2, 0x92, 0x67, 0x35, 0x78, 0x16, 0x21, 0x91,
    0x26, 0x49, 0x60, 0xeb, 0x06, 0xa7, 0xca, 0xcb);

uint32_t timeStamp = 0;
//ULTRA READ BUFFER
uint8_t hts_buf[5] = {0xAA, 0x04, 0x05, 0x04, 0x05};


/** 
* Connection call back function
*/
static void connected(struct bt_conn *conn, uint8_t conn_err) {
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (conn_err) {
		printk("Failed to connect to %s (%u)\n", addr, conn_err);

		bt_conn_unref(connection);
		connection = NULL;

		start_scan();
		return;
	}

	if (conn != connection) {
        return;
    }
    bluetooth = true;
    printk("Connected: %s\n", addr);
}

/** 
* Disconnect callback function
*/
static void disconnected(struct bt_conn *conn, uint8_t reason)
{
	char addr[BT_ADDR_LE_STR_LEN];
    //int err;

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (conn != connection) {
		return;
	}

	bt_conn_unref(connection);
	connection = NULL;
    bluetooth = false;

    printk("Disconnected: %s (reason 0x%02x)\n", addr, reason);
	start_scan();
}

/** 
*register connection callback struct
*/
static struct bt_conn_cb conn_callbacks = {
    .connected = connected,
    .disconnected = disconnected,
};

/**
* Function to parse through advertising data and connect to the AHU
*/
static bool eir_found(struct bt_data *data, void *user_data)
{
	bt_addr_le_t *addr = user_data;
    int count = 0;

	//printk("[AD]: %u data_len %u\n", data->type, data->data_len);

	if (data->type == BT_DATA_UUID128_ALL) {
    
        uint16_t u16 = 0;

        for (int i = 0; i < data->data_len; i++) {

            u16 = data->data[i];
            if (u16 == ahu_uuid[i]) {
                count++;
            }
        }

        if (count == UUID_BUFFER) {

            printk("AHU Found\n");

            int err = bt_le_scan_stop();
            if (err) {
                printk("Stop LE scan failed (err %d)\n", err);
            }

            err = bt_conn_le_create(addr, BT_CONN_LE_CREATE_CONN,
                        BT_LE_CONN_PARAM_DEFAULT,
                        &connection);
            if (err) {
                printk("Create connection failed (err %d)\n",
                    err);
                start_scan();
            }

            return false;

        }
	}
	

	return true;
}

/**
* Fucntion to find device 
*/
static void device_found(const bt_addr_le_t *addr, int8_t rssi, uint8_t type,
			 struct net_buf_simple *ad)
{
	char dev[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(addr, dev, sizeof(dev));
	printk("[DEVICE]: %s, AD evt type %u, AD data len %u, RSSI %i\n",
	       dev, type, ad->len, rssi);

	/* We're only interested in connectable events */
	/* We're only interested in connectable events */
    if (type == BT_GAP_ADV_TYPE_ADV_IND ||
        type == BT_GAP_ADV_TYPE_ADV_DIRECT_IND)
    {
        bt_data_parse(ad, eir_found, (void *)addr);
    }
}

/**
* Function to start scan
*/
void start_scan(void)
{
	int err;

	/* This demo doesn't require active scan */
	err = bt_le_scan_start(BT_LE_SCAN_PASSIVE, device_found);
	if (err) {
		printk("Scanning failed to start (err %d)\n", err);
		return;
	}

	printk("Scanning successfully started\n");
}

/**
* Function to stop scan
*/
void stop_scan(void)
{
	int err;

	/* This demo doesn't require active scan */
	err = bt_le_scan_stop();
	if (err) {
		printk("Scanning failed to stop (err %d)\n", err);
		return;
	}

	printk("Scanning successfully stopped\n");
}

/**
* Thread to initialise bluetooth and scan and connetc to the right device
*/
void thread_bsu_ble_init (void) {
    int err;

	err = bt_enable(NULL);
	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
		return;
	}

	printk("Bluetooth initialized\n");

    bt_conn_cb_register(&conn_callbacks);

	start_scan();
}

/**
* Function to read vlaues from the ultrasonic sensor to the respective buffer
*/
uint8_t read_hts(struct bt_conn *conn, uint8_t err,
                               struct bt_gatt_read_params *params,
                               const void *data, uint16_t length) {

    memcpy(&hts_buf, data, sizeof(hts_buf));
    
    printk("sensor : %u %d %d %u %u \r\n", hts_buf[0], hts_buf[1], hts_buf[2], hts_buf[3], hts_buf[4]);
    return 0;
}


/**
* Function to start reading the ultrasonic values from the AHU
*/
void thread_ble_read_out(void) {

    static struct bt_gatt_read_params read_param_ultra = {
        .func = read_hts,
        .handle_count = 0,
        .by_uuid.uuid = &ultra_uuid.uuid,
        .by_uuid.start_handle = BT_ATT_FIRST_ATTRIBUTE_HANDLE,
        .by_uuid.end_handle = BT_ATT_LAST_ATTRIBUTE_HANDLE,
    };


    while (1) {

        if (bluetooth)
        {
            uint32_t time_ms = k_uptime_get();
            timeStamp = time_ms/1000;
            bt_gatt_read(connection, &read_param_ultra);

        }

        k_usleep(100);
    }
}

/*Start the thread to initialise the bluetooth for the BSU*/
K_THREAD_DEFINE(ble_init, THREAD_BLE_BASE_STACK, thread_bsu_ble_init, NULL, NULL, NULL, THREAD_PRIORITY_BLE_BASE, 0, 0);

/*Start the thread to initialise the thread for reading values from the AHU to the BSU*/
K_THREAD_DEFINE(ble_read, THREAD_BLE_BASE_STACK, thread_ble_read_out, NULL, NULL, NULL, THREAD_PRIORITY_READ_BASE, 0, 0);

void main() {

}