/*
 * Copyright (c) 2022 Libre Solar Technologies GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <string.h>


#define SW0 DT_NODELABEL(button0)
#define LED0 DT_NODELABEL(led0)

#define DEBOUNCE_TIMEOUT_MS 50

static
const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(SW0, gpios);
static
const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0, gpios);

uint64_t last_time = 0;
struct gpio_callback button_cb_data;

void button_callback(const struct device *dev,
	struct gpio_callback *cb, uint32_t pins)
{
  uint64_t now = k_uptime_get();
  if ((now - last_time) > DEBOUNCE_TIMEOUT_MS)
  {
    gpio_pin_toggle_dt(&led);
  }
  last_time = now;
}

void main(void)
{
  // make sure the GPIO device is ready
  if (!device_is_ready(button.port))
    return;

  // configure the LED pin as output
  gpio_pin_configure_dt(&led, GPIO_OUTPUT);

  // configure the button pin as input
  gpio_pin_configure_dt(&button, GPIO_INPUT);
  // configure the interrupt on button press (pin goes from low to high)
  gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);

  // setup the button press callback
  gpio_init_callback(&button_cb_data, button_callback, BIT(button.pin));
  gpio_add_callback(button.port, &button_cb_data);
}

