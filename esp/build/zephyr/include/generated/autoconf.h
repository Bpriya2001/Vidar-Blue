#define CONFIG_GPIO 1
#define CONFIG_GPIO_INIT_PRIORITY 40
#define CONFIG_UART_INTERRUPT_DRIVEN 1
#define CONFIG_BOARD "esp32c3_devkitm"
#define CONFIG_HEAP_MEM_POOL_SIZE 16384
#define CONFIG_ROM_START_OFFSET 0x0
#define CONFIG_SOC "esp32c3"
#define CONFIG_NUM_IRQS 62
#define CONFIG_GEN_ISR_TABLES 1
#define CONFIG_GEN_SW_ISR_TABLE 1
#define CONFIG_DYNAMIC_INTERRUPTS 1
#define CONFIG_ISR_STACK_SIZE 2048
#define CONFIG_ATOMIC_OPERATIONS_C 1
#define CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC 16000000
#define CONFIG_RISCV_GENERIC_TOOLCHAIN 1
#define CONFIG_FLASH_BASE_ADDRESS 0x0
#define CONFIG_RISCV_GP 1
#define CONFIG_SYS_CLOCK_TICKS_PER_SEC 1000
#define CONFIG_PINCTRL 1
#define CONFIG_GEN_IRQ_START_VECTOR 0
#define CONFIG_MAIN_STACK_SIZE 2048
#define CONFIG_IDLE_STACK_SIZE 512
#define CONFIG_TEST_EXTRA_STACK_SIZE 1024
#define CONFIG_MP_MAX_NUM_CPUS 1
#define CONFIG_KERNEL_ENTRY "__start"
#define CONFIG_RISCV_SOC_MCAUSE_EXCEPTION_MASK 0x7FFFFFFF
#define CONFIG_CLOCK_CONTROL 1
#define CONFIG_SERIAL_INIT_PRIORITY 50
#define CONFIG_XIP 1
#define CONFIG_HAS_DTS 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_FLASH_CONTROLLER_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_GPIO_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_I2C_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_INTC_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_PINCTRL_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_RTC_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_RTC_TIMER_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_SPI_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_SYSTIMER_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_TRNG_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_UART_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_USB_SERIAL_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_ESP32_WATCHDOG_ENABLED 1
#define CONFIG_DT_HAS_ESPRESSIF_RISCV_ENABLED 1
#define CONFIG_DT_HAS_FIXED_PARTITIONS_ENABLED 1
#define CONFIG_DT_HAS_GPIO_KEYS_ENABLED 1
#define CONFIG_DT_HAS_MMIO_SRAM_ENABLED 1
#define CONFIG_DT_HAS_SOC_NV_FLASH_ENABLED 1
#define CONFIG_DT_HAS_ZEPHYR_POWER_STATE_ENABLED 1
#define CONFIG_TAINT_BLOBS 1
#define CONFIG_ZEPHYR_CANOPENNODE_MODULE 1
#define CONFIG_ZEPHYR_CHRE_MODULE 1
#define CONFIG_ZEPHYR_FATFS_MODULE 1
#define CONFIG_ZEPHYR_HAL_ESPRESSIF_MODULE 1
#define CONFIG_ARM_ETHOS_U_LOG_LEVEL_INF 1
#define CONFIG_ARM_ETHOS_U_LOG_LEVEL 3
#define CONFIG_ZEPHYR_HAL_ETHOS_U_MODULE 1
#define CONFIG_ZEPHYR_HAL_GIGADEVICE_MODULE 1
#define CONFIG_ZEPHYR_HAL_INFINEON_MODULE 1
#define CONFIG_ZEPHYR_HAL_NORDIC_MODULE 1
#define CONFIG_ZEPHYR_HAL_NXP_MODULE 1
#define CONFIG_ZEPHYR_HAL_RPI_PICO_MODULE 1
#define CONFIG_ZEPHYR_HAL_TELINK_MODULE 1
#define CONFIG_ZEPHYR_LIBLC3_MODULE 1
#define CONFIG_ZEPHYR_LITTLEFS_MODULE 1
#define CONFIG_ZEPHYR_LORAMAC_NODE_MODULE 1
#define CONFIG_ZEPHYR_LVGL_MODULE 1
#define CONFIG_ZEPHYR_LZ4_MODULE 1
#define CONFIG_ZEPHYR_MBEDTLS_MODULE 1
#define CONFIG_ZEPHYR_NANOPB_MODULE 1
#define CONFIG_ZEPHYR_OPENTHREAD_MODULE 1
#define CONFIG_ZEPHYR_PICOLIBC_MODULE 1
#define CONFIG_ZEPHYR_SOF_MODULE 1
#define CONFIG_ZEPHYR_TFLITE_MICRO_MODULE 1
#define CONFIG_ZEPHYR_TRACERECORDER_MODULE 1
#define CONFIG_ZEPHYR_TRUSTED_FIRMWARE_M_MODULE 1
#define CONFIG_ZEPHYR_TRUSTED_FIRMWARE_A_MODULE 1
#define CONFIG_ZEPHYR_UOSCORE_UEDHOC_MODULE 1
#define CONFIG_ZEPHYR_ZCBOR_MODULE 1
#define CONFIG_ZEPHYR_ZSCILIB_MODULE 1
#define CONFIG_HAS_ESPRESSIF_HAL 1
#define CONFIG_TINYCRYPT 1
#define CONFIG_TINYCRYPT_SHA256 1
#define CONFIG_TINYCRYPT_SHA256_HMAC 1
#define CONFIG_TINYCRYPT_SHA256_HMAC_PRNG 1
#define CONFIG_TINYCRYPT_AES 1
#define CONFIG_TINYCRYPT_AES_CMAC 1
#define CONFIG_BOARD_REVISION ""
#define CONFIG_BOARD_ESP32C3_DEVKITM 1
#define CONFIG_SOC_ESP32C3 1
#define CONFIG_IDF_TARGET_ESP32C3 1
#define CONFIG_ESPTOOLPY_FLASHFREQ_80M 1
#define CONFIG_FLASH_SIZE 4194304
#define CONFIG_ESP32C3_RTC_CLK_SRC_INT_RC 1
#define CONFIG_ESP32C3_RTC_CLK_CAL_CYCLES 1024
#define CONFIG_ESP32_PHY_MAX_WIFI_TX_POWER 20
#define CONFIG_ESP32_PHY_MAX_TX_POWER 20
#define CONFIG_SOC_LOG_LEVEL_INF 1
#define CONFIG_SOC_LOG_LEVEL 3
#define CONFIG_ARCH "riscv32"
#define CONFIG_ARCH_IRQ_VECTOR_TABLE_ALIGN 256
#define CONFIG_RISCV_ISA_RV32I 1
#define CONFIG_RISCV_ISA_EXT_M 1
#define CONFIG_RISCV_ISA_EXT_A 1
#define CONFIG_RISCV_ISA_EXT_ZICSR 1
#define CONFIG_RISCV_ISA_EXT_ZIFENCEI 1
#define CONFIG_RISCV 1
#define CONFIG_ARCH_IS_SET 1
#define CONFIG_ARCH_LOG_LEVEL_INF 1
#define CONFIG_ARCH_LOG_LEVEL 3
#define CONFIG_LITTLE_ENDIAN 1
#define CONFIG_SRAM_SIZE 320
#define CONFIG_SRAM_BASE_ADDRESS 0x3fc7c000
#define CONFIG_ARCH_SW_ISR_TABLE_ALIGN 4
#define CONFIG_ARCH_SUPPORTS_COREDUMP 1
#define CONFIG_ARCH_HAS_THREAD_LOCAL_STORAGE 1
#define CONFIG_ARCH_HAS_CODE_DATA_RELOCATION 1
#define CONFIG_TOOLCHAIN_HAS_BUILTIN_FFS 1
#define CONFIG_KERNEL_LOG_LEVEL_INF 1
#define CONFIG_KERNEL_LOG_LEVEL 3
#define CONFIG_MULTITHREADING 1
#define CONFIG_NUM_COOP_PRIORITIES 16
#define CONFIG_NUM_PREEMPT_PRIORITIES 15
#define CONFIG_MAIN_THREAD_PRIORITY 0
#define CONFIG_COOP_ENABLED 1
#define CONFIG_PREEMPT_ENABLED 1
#define CONFIG_PRIORITY_CEILING -127
#define CONFIG_NUM_METAIRQ_PRIORITIES 0
#define CONFIG_THREAD_STACK_INFO 1
#define CONFIG_ERRNO 1
#define CONFIG_SCHED_DUMB 1
#define CONFIG_WAITQ_DUMB 1
#define CONFIG_INIT_STACKS 1
#define CONFIG_BOOT_BANNER 1
#define CONFIG_BOOT_DELAY 0
#define CONFIG_THREAD_MONITOR 1
#define CONFIG_THREAD_NAME 1
#define CONFIG_THREAD_MAX_NAME_LEN 32
#define CONFIG_SYSTEM_WORKQUEUE_STACK_SIZE 1024
#define CONFIG_SYSTEM_WORKQUEUE_PRIORITY -1
#define CONFIG_TIMESLICING 1
#define CONFIG_TIMESLICE_SIZE 0
#define CONFIG_TIMESLICE_PRIORITY 0
#define CONFIG_POLL 1
#define CONFIG_NUM_MBOX_ASYNC_MSGS 10
#define CONFIG_KERNEL_MEM_POOL 1
#define CONFIG_SYS_CLOCK_EXISTS 1
#define CONFIG_TIMEOUT_64BIT 1
#define CONFIG_SYS_CLOCK_MAX_TIMEOUT_DAYS 365
#define CONFIG_KERNEL_INIT_PRIORITY_OBJECTS 30
#define CONFIG_KERNEL_INIT_PRIORITY_DEFAULT 40
#define CONFIG_KERNEL_INIT_PRIORITY_DEVICE 50
#define CONFIG_APPLICATION_INIT_PRIORITY 90
#define CONFIG_USE_SWITCH 1
#define CONFIG_USE_SWITCH_SUPPORTED 1
#define CONFIG_MP_NUM_CPUS 1
#define CONFIG_TICKLESS_KERNEL 1
#define CONFIG_TOOLCHAIN_SUPPORTS_THREAD_LOCAL_STORAGE 1
#define CONFIG_BT_DRIVERS 1
#define CONFIG_BT_ESP32 1
#define CONFIG_BT_DRIVER_QUIRK_NO_AUTO_DLE 1
#define CONFIG_CONSOLE 1
#define CONFIG_CONSOLE_INPUT_MAX_LINE_LEN 128
#define CONFIG_CONSOLE_HAS_DRIVER 1
#define CONFIG_CONSOLE_INIT_PRIORITY 60
#define CONFIG_UART_CONSOLE 1
#define CONFIG_UART_CONSOLE_LOG_LEVEL_INF 1
#define CONFIG_UART_CONSOLE_LOG_LEVEL 3
#define CONFIG_ETH_INIT_PRIORITY 80
#define CONFIG_SERIAL 1
#define CONFIG_SERIAL_HAS_DRIVER 1
#define CONFIG_SERIAL_SUPPORT_ASYNC 1
#define CONFIG_SERIAL_SUPPORT_INTERRUPT 1
#define CONFIG_UART_LOG_LEVEL_INF 1
#define CONFIG_UART_LOG_LEVEL 3
#define CONFIG_UART_USE_RUNTIME_CONFIGURE 1
#define CONFIG_UART_LINE_CTRL 1
#define CONFIG_UART_ESP32 1
#define CONFIG_SERIAL_ESP32_USB 1
#define CONFIG_INTC_INIT_PRIORITY 40
#define CONFIG_INTC_LOG_LEVEL_INF 1
#define CONFIG_INTC_LOG_LEVEL 3
#define CONFIG_INTC_ESP32C3 1
#define CONFIG_TIMER_HAS_64BIT_CYCLE_COUNTER 1
#define CONFIG_SYSTEM_CLOCK_INIT_PRIORITY 0
#define CONFIG_TICKLESS_CAPABLE 1
#define CONFIG_ESP32C3_SYS_TIMER 1
#define CONFIG_GPIO_LOG_LEVEL_INF 1
#define CONFIG_GPIO_LOG_LEVEL 3
#define CONFIG_GPIO_ESP32 1
#define CONFIG_FXL6408_LOG_LEVEL_INF 1
#define CONFIG_FXL6408_LOG_LEVEL 3
#define CONFIG_CLOCK_CONTROL_INIT_PRIORITY 30
#define CONFIG_CLOCK_CONTROL_LOG_LEVEL_INF 1
#define CONFIG_CLOCK_CONTROL_LOG_LEVEL 3
#define CONFIG_CLOCK_CONTROL_ESP32 1
#define CONFIG_PINCTRL_LOG_LEVEL_INF 1
#define CONFIG_PINCTRL_LOG_LEVEL 3
#define CONFIG_PINCTRL_ESP32 1
#define CONFIG_USBC_LOG_LEVEL_INF 1
#define CONFIG_USBC_LOG_LEVEL 3
#define CONFIG_SUPPORT_MINIMAL_LIBC 1
#define CONFIG_PICOLIBC_SUPPORTED 1
#define CONFIG_MINIMAL_LIBC 1
#define CONFIG_HAS_NEWLIB_LIBC_NANO 1
#define CONFIG_MINIMAL_LIBC_NON_REENTRANT_FUNCTIONS 1
#define CONFIG_MINIMAL_LIBC_MALLOC 1
#define CONFIG_MINIMAL_LIBC_MALLOC_ARENA_SIZE 0
#define CONFIG_MINIMAL_LIBC_CALLOC 1
#define CONFIG_MINIMAL_LIBC_REALLOCARRAY 1
#define CONFIG_MINIMAL_LIBC_TIME 1
#define CONFIG_STDOUT_CONSOLE 1
#define CONFIG_NEED_LIBC_MEM_PARTITION 1
#define CONFIG_RING_BUFFER 1
#define CONFIG_CRC 1
#define CONFIG_MPSC_PBUF 1
#define CONFIG_CBPRINTF_COMPLETE 1
#define CONFIG_CBPRINTF_FULL_INTEGRAL 1
#define CONFIG_CBPRINTF_FP_SUPPORT 1
#define CONFIG_CBPRINTF_N_SPECIFIER 1
#define CONFIG_CBPRINTF_PACKAGE_LOG_LEVEL_INF 1
#define CONFIG_CBPRINTF_PACKAGE_LOG_LEVEL 3
#define CONFIG_SYS_HEAP_ALLOC_LOOPS 3
#define CONFIG_SYS_HEAP_AUTO 1
#define CONFIG_GETOPT 1
#define CONFIG_POSIX_MAX_FDS 4
#define CONFIG_MAX_TIMER_COUNT 5
#define CONFIG_TIMER_CREATE_WAIT 100
#define CONFIG_FNMATCH 1
#define CONFIG_BT 1
#define CONFIG_BT_LOG_LEVEL_INF 1
#define CONFIG_BT_LOG_LEVEL 3
#define CONFIG_BT_HCI 1
#define CONFIG_BT_CENTRAL 1
#define CONFIG_BT_OBSERVER 1
#define CONFIG_BT_CONN 1
#define CONFIG_BT_MAX_CONN 1
#define CONFIG_BT_CONN_TX 1
#define CONFIG_BT_PHY_UPDATE 1
#define CONFIG_BT_DATA_LEN_UPDATE 1
#define CONFIG_BT_BUF_ACL_TX_SIZE 27
#define CONFIG_BT_BUF_ACL_TX_COUNT 3
#define CONFIG_BT_BUF_ACL_RX_SIZE 69
#define CONFIG_BT_BUF_ACL_RX_COUNT 6
#define CONFIG_BT_BUF_EVT_RX_SIZE 68
#define CONFIG_BT_BUF_EVT_RX_COUNT 10
#define CONFIG_BT_BUF_EVT_DISCARDABLE_SIZE 43
#define CONFIG_BT_BUF_EVT_DISCARDABLE_COUNT 3
#define CONFIG_BT_BUF_CMD_TX_SIZE 65
#define CONFIG_BT_BUF_CMD_TX_COUNT 2
#define CONFIG_BT_RPA 1
#define CONFIG_BT_ASSERT 1
#define CONFIG_BT_ASSERT_VERBOSE 1
#define CONFIG_BT_DEBUG 1
#define CONFIG_BT_DEBUG_LOG 1
#define CONFIG_BT_HCI_DRIVER_LOG_LEVEL 3
#define CONFIG_BT_HCI_DRIVER_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_RPA_LOG_LEVEL 3
#define CONFIG_BT_RPA_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_LONG_WQ 1
#define CONFIG_BT_LONG_WQ_STACK_SIZE 1300
#define CONFIG_BT_LONG_WQ_PRIO 10
#define CONFIG_BT_HCI_HOST 1
#define CONFIG_BT_HCI_TX_STACK_SIZE 1024
#define CONFIG_BT_HCI_TX_PRIO 7
#define CONFIG_BT_HCI_RESERVE 1
#define CONFIG_BT_RECV_WORKQ_BT 1
#define CONFIG_BT_RX_STACK_SIZE 1200
#define CONFIG_BT_RX_PRIO 8
#define CONFIG_BT_DRIVER_RX_HIGH_PRIO 6
#define CONFIG_BT_HOST_CRYPTO 1
#define CONFIG_BT_HOST_CRYPTO_PRNG 1
#define CONFIG_BT_CONN_TX_MAX 3
#define CONFIG_BT_AUTO_PHY_UPDATE 1
#define CONFIG_BT_AUTO_DATA_LEN_UPDATE 1
#define CONFIG_BT_SMP 1
#define CONFIG_BT_BONDABLE 1
#define CONFIG_BT_SMP_ENFORCE_MITM 1
#define CONFIG_BT_SMP_MIN_ENC_KEY_SIZE 7
#define CONFIG_BT_L2CAP_TX_BUF_COUNT 3
#define CONFIG_BT_L2CAP_TX_FRAG_COUNT 2
#define CONFIG_BT_L2CAP_TX_MTU 65
#define CONFIG_BT_L2CAP_LOG_LEVEL 3
#define CONFIG_BT_L2CAP_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_ATT_ENFORCE_FLOW 1
#define CONFIG_BT_ATT_PREPARE_COUNT 0
#define CONFIG_BT_ATT_RETRY_ON_SEC_ERR 1
#define CONFIG_BT_GATT_AUTO_RESUBSCRIBE 1
#define CONFIG_BT_GATT_AUTO_SEC_REQ 1
#define CONFIG_BT_GATT_SERVICE_CHANGED 1
#define CONFIG_BT_GATT_CACHING 1
#define CONFIG_BT_GATT_ENFORCE_SUBSCRIPTION 1
#define CONFIG_BT_GATT_CLIENT 1
#define CONFIG_BT_GATT_READ_MULTIPLE 1
#define CONFIG_BT_GATT_READ_MULT_VAR_LEN 1
#define CONFIG_BT_ATT_LOG_LEVEL 3
#define CONFIG_BT_ATT_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_GATT_LOG_LEVEL 3
#define CONFIG_BT_GATT_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_IAS_CLIENT_LOG_LEVEL 3
#define CONFIG_BT_IAS_CLIENT_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_IAS_LOG_LEVEL_INF 1
#define CONFIG_BT_IAS_LOG_LEVEL 3
#define CONFIG_BT_MAX_PAIRED 1
#define CONFIG_BT_CREATE_CONN_TIMEOUT 3
#define CONFIG_BT_CONN_PARAM_UPDATE_TIMEOUT 5000
#define CONFIG_BT_CONN_PARAM_RETRY_COUNT 3
#define CONFIG_BT_CONN_PARAM_RETRY_TIMEOUT 5000
#define CONFIG_BT_BACKGROUND_SCAN_INTERVAL 2048
#define CONFIG_BT_BACKGROUND_SCAN_WINDOW 18
#define CONFIG_BT_DEVICE_NAME "Zephyr"
#define CONFIG_BT_DEVICE_APPEARANCE 0
#define CONFIG_BT_ID_MAX 1
#define CONFIG_BT_ECC 1
#define CONFIG_BT_SETTINGS_LOG_LEVEL 3
#define CONFIG_BT_SETTINGS_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_HCI_CORE_LOG_LEVEL 3
#define CONFIG_BT_HCI_CORE_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_CONN_LOG_LEVEL 3
#define CONFIG_BT_CONN_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_ISO_LOG_LEVEL 3
#define CONFIG_BT_ISO_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_KEYS_LOG_LEVEL 3
#define CONFIG_BT_KEYS_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_SMP_LOG_LEVEL 3
#define CONFIG_BT_SMP_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_RFCOMM_LOG_LEVEL 3
#define CONFIG_BT_RFCOMM_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_HFP_HF_LOG_LEVEL 3
#define CONFIG_BT_HFP_HF_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_AVDTP_LOG_LEVEL 3
#define CONFIG_BT_AVDTP_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_A2DP_LOG_LEVEL 3
#define CONFIG_BT_A2DP_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_SDP_LOG_LEVEL 3
#define CONFIG_BT_SDP_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_SERVICE_LOG_LEVEL 3
#define CONFIG_BT_SERVICE_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_CRYPTO 1
#define CONFIG_BT_CRYPTO_LOG_LEVEL 3
#define CONFIG_BT_CRYPTO_LOG_LEVEL_INHERIT 1
#define CONFIG_BT_COMPANY_ID 0x05F1
#define CONFIG_PRINTK 1
#define CONFIG_EARLY_CONSOLE 1
#define CONFIG_ASSERT_VERBOSE 1
#define CONFIG_LOG 1
#define CONFIG_LOG_CORE_INIT_PRIORITY 0
#define CONFIG_LOG_MODE_DEFERRED 1
#define CONFIG_LOG_RUNTIME_FILTERING 1
#define CONFIG_LOG_DEFAULT_LEVEL 3
#define CONFIG_LOG_OVERRIDE_LEVEL 0
#define CONFIG_LOG_MAX_LEVEL 4
#define CONFIG_LOG_PRINTK 1
#define CONFIG_LOG_MODE_OVERFLOW 1
#define CONFIG_LOG_PROCESS_TRIGGER_THRESHOLD 10
#define CONFIG_LOG_PROCESS_THREAD 1
#define CONFIG_LOG_PROCESS_THREAD_STARTUP_DELAY_MS 0
#define CONFIG_LOG_PROCESS_THREAD_SLEEP_MS 1000
#define CONFIG_LOG_PROCESS_THREAD_STACK_SIZE 768
#define CONFIG_LOG_BUFFER_SIZE 1024
#define CONFIG_LOG_TRACE_SHORT_TIMESTAMP 1
#define CONFIG_LOG_FUNC_NAME_PREFIX_ERR 1
#define CONFIG_LOG_FUNC_NAME_PREFIX_WRN 1
#define CONFIG_LOG_FUNC_NAME_PREFIX_INF 1
#define CONFIG_LOG_FUNC_NAME_PREFIX_DBG 1
#define CONFIG_LOG_TAG_MAX_LEN 0
#define CONFIG_LOG_DOMAIN_ID 0
#define CONFIG_LOG_CMDS 1
#define CONFIG_LOG_USE_VLA 1
#define CONFIG_LOG_MEM_UTILIZATION 1
#define CONFIG_LOG_FAILURE_REPORT_PERIOD 1000
#define CONFIG_LOG_DOMAIN_NAME ""
#define CONFIG_LOG_OUTPUT 1
#define CONFIG_NET_BUF 1
#define CONFIG_NET_BUF_LOG_LEVEL_INF 1
#define CONFIG_NET_BUF_LOG_LEVEL 3
#define CONFIG_SHELL 1
#define CONFIG_SHELL_LOG_LEVEL_INF 1
#define CONFIG_SHELL_LOG_LEVEL 3
#define CONFIG_SHELL_BACKENDS 1
#define CONFIG_SHELL_BACKEND_SERIAL 1
#define CONFIG_SHELL_BACKEND_SERIAL_INIT_PRIORITY 0
#define CONFIG_SHELL_PROMPT_UART "CSSE4011:~$ "
#define CONFIG_SHELL_BACKEND_SERIAL_INTERRUPT_DRIVEN 1
#define CONFIG_SHELL_BACKEND_SERIAL_TX_RING_BUFFER_SIZE 8
#define CONFIG_SHELL_BACKEND_SERIAL_RX_RING_BUFFER_SIZE 64
#define CONFIG_SHELL_BACKEND_SERIAL_LOG_MESSAGE_QUEUE_TIMEOUT 100
#define CONFIG_SHELL_BACKEND_SERIAL_LOG_MESSAGE_QUEUE_SIZE 512
#define CONFIG_SHELL_BACKEND_SERIAL_LOG_LEVEL_DEFAULT 1
#define CONFIG_SHELL_BACKEND_SERIAL_LOG_LEVEL 5
#define CONFIG_SHELL_STACK_SIZE 2048
#define CONFIG_SHELL_BACKSPACE_MODE_DELETE 1
#define CONFIG_SHELL_CMD_BUFF_SIZE 256
#define CONFIG_SHELL_PRINTF_BUFF_SIZE 30
#define CONFIG_SHELL_DEFAULT_TERMINAL_WIDTH 80
#define CONFIG_SHELL_DEFAULT_TERMINAL_HEIGHT 24
#define CONFIG_SHELL_ARGC_MAX 20
#define CONFIG_SHELL_TAB 1
#define CONFIG_SHELL_TAB_AUTOCOMPLETION 1
#define CONFIG_SHELL_WILDCARD 1
#define CONFIG_SHELL_ECHO_STATUS 1
#define CONFIG_SHELL_VT100_COMMANDS 1
#define CONFIG_SHELL_VT100_COLORS 1
#define CONFIG_SHELL_METAKEYS 1
#define CONFIG_SHELL_HELP 1
#define CONFIG_SHELL_HELP_OPT_PARSE 1
#define CONFIG_SHELL_HELP_ON_WRONG_ARGUMENT_COUNT 1
#define CONFIG_SHELL_HISTORY 1
#define CONFIG_SHELL_HISTORY_BUFFER 512
#define CONFIG_SHELL_STATS 1
#define CONFIG_SHELL_CMDS 1
#define CONFIG_SHELL_CMDS_RESIZE 1
#define CONFIG_SHELL_CMD_ROOT ""
#define CONFIG_SHELL_LOG_BACKEND 1
#define CONFIG_SHELL_LOG_FORMAT_TIMESTAMP 1
#define CONFIG_SHELL_AUTOSTART 1
#define CONFIG_KERNEL_SHELL 1
#define CONFIG_DEVICE_SHELL 1
#define CONFIG_DEVMEM_SHELL 1
#define CONFIG_COVERAGE_GCOV_HEAP_SIZE 16384
#define CONFIG_TOOLCHAIN_ZEPHYR_0_15 1
#define CONFIG_TOOLCHAIN_ZEPHYR_SUPPORTS_THREAD_LOCAL_STORAGE 1
#define CONFIG_LINKER_ORPHAN_SECTION_WARN 1
#define CONFIG_LD_LINKER_SCRIPT_SUPPORTED 1
#define CONFIG_LD_LINKER_TEMPLATE 1
#define CONFIG_LINKER_SORT_BY_ALIGNMENT 1
#define CONFIG_SRAM_OFFSET 0x0
#define CONFIG_LINKER_GENERIC_SECTIONS_PRESENT_AT_BOOT 1
#define CONFIG_LINKER_LAST_SECTION_ID 1
#define CONFIG_LINKER_LAST_SECTION_ID_PATTERN 0xE015E015
#define CONFIG_LINKER_USE_RELAX 1
#define CONFIG_SIZE_OPTIMIZATIONS 1
#define CONFIG_COMPILER_COLOR_DIAGNOSTICS 1
#define CONFIG_FORTIFY_SOURCE_NONE 1
#define CONFIG_COMPILER_OPT ""
#define CONFIG_RUNTIME_ERROR_CHECKS 1
#define CONFIG_KERNEL_BIN_NAME "zephyr"
#define CONFIG_OUTPUT_STAT 1
#define CONFIG_OUTPUT_DISASSEMBLY 1
#define CONFIG_OUTPUT_PRINT_MEMORY_USAGE 1
#define CONFIG_BUILD_OUTPUT_BIN 1
#define CONFIG_WARN_DEPRECATED 1
#define CONFIG_TAINT 1
#define CONFIG_ENFORCE_ZEPHYR_STDINT 1
#define CONFIG_BOOTLOADER_ESP_IDF 1
#define CONFIG_COMPAT_INCLUDES 1
