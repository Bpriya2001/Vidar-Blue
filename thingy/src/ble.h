#ifndef BLE_H
#define BLE_H

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

#define THREAD_BLE_BASE_STACK 4094
#define THREAD_PRIORITY_BLE_BASE -2

void ble_thread_init();
extern uint8_t sensor_buf[5];
//extern uint16_t co2_tvoc_buf[2];

#endif 