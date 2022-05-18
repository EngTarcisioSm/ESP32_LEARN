#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void task1(void *pvParameters) {

	for (;;) {
		printf("reading temperature from %s\n", (char *) pvParameters);
		vTaskDelay( 1000 / portTICK_PERIOD_MS);
	}
}

void task2(void *pvParameters) {

	for (;;) {
		printf("reading humidity from %s\n", (char *) pvParameters);
		vTaskDelay( 500 / portTICK_PERIOD_MS);
	}
}

void app_main(void) {
	xTaskCreate(&task1, "task1", 2048, "Now", 2, NULL);
	xTaskCreate(&task2, "task2", 2048, "later", 2, NULL);
}

