#include <stdio.h>

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIN		4


void vConfigPin() {
	gpio_pad_select_gpio(PIN);					//seleciona o pino a ser configurado
	gpio_set_direction(PIN, GPIO_MODE_OUTPUT);	//define o pino como saída
}

void app_main(void)
{
	vConfigPin();
	int isOn = 0;

	while(1) {
		isOn = !isOn;
		gpio_set_level(PIN, isOn);

		vTaskDelay( 200 / portTICK_PERIOD_MS);
	}
}
