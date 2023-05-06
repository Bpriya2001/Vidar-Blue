#include <zephyr/device.h>
#include <zephyr/toolchain.h>

/* 1 : /soc/rtc@60008000:
 * Supported:
 *    - /soc/uart@60000000
 *    - /soc/uart@60043000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_27[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 3, 4, DEVICE_HANDLE_ENDS };

/* 2 : /soc/gpio@60004000:
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_12[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 3 : /soc/uart@60000000:
 * Direct Dependencies:
 *    - /soc/rtc@60008000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_39[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 4 : /soc/uart@60043000:
 * Direct Dependencies:
 *    - /soc/rtc@60008000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_41[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };
