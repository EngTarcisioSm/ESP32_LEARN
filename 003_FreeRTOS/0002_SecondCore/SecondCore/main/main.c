#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static TaskHandle_t xReceiverHandler = NULL;

void task1(void *pvParameters) {
	for (;;) {
		printf("reading temperature from %s \n", (char*) pvParameters);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}

void task2(void *pvParameters) {
	for (;;) {
		printf("reading humidity from %s \n", (char*) pvParameters);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}

void vTask1(void *pvParameter) {

	for (;;) {
		xTaskNotifyGive(xReceiverHandler);
		vTaskDelay(1500 / portTICK_PERIOD_MS);
	}
}

void vTask2(void *pvParameter) {

	for (;;) {
		ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
		printf("received notification\n");
	}
}

void app_main(void) {


	xTaskCreate(&vTask1, "Sender", 2048, NULL, 2, &xReceiverHandler);
	xTaskCreate(&vTask2, "Receiver", 2048, NULL, 2, NULL);


}
