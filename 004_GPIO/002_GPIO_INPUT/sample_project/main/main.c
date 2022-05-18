#include <stdio.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIN_LED		GPIO_NUM_4
#define PIN_SWITCH	GPIO_NUM_17

void vConfigPins(void) {
	gpio_pad_select_gpio(PIN_LED);
	gpio_set_direction(PIN_LED, GPIO_MODE_OUTPUT);
	gpio_pulldown_dis(PIN_LED);
	gpio_pullup_dis(PIN_LED);


	gpio_pad_select_gpio(PIN_SWITCH);
	gpio_set_direction(PIN_SWITCH, GPIO_MODE_INPUT);
	gpio_pulldown_en(PIN_SWITCH);
	gpio_pullup_dis(PIN_SWITCH);
}

void app_main(void)
{
	vConfigPins();


	while(true) {
		bool bLevelPin = (bool)gpio_get_level(PIN_SWITCH);
		gpio_set_level(PIN_LED, bLevelPin);
		vTaskDelay(1);
	}
}
