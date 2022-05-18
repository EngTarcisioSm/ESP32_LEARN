#include <stdio.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void vConfigPin() {
	gpio_pad_select_gpio(GPIO_NUM_4);
	gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);
}


void app_main(void)
{
	bool bStatePin = 0;

	vConfigPin();


	while(true) {
		bStatePin = !bStatePin;
		gpio_set_level(GPIO_NUM_4, bStatePin);
		vTaskDelay( 250 / portTICK_PERIOD_MS );
	}

}
