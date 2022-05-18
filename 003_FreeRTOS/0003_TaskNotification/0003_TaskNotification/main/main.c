#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/*****************************************************************************/
/* Variaveis */
//static TaskHandle_t xReceiverHandler = NULL;

/*
void vTaskSender (void *pvParameter) {

	for(;;) {
		xTaskNotifyGive(xReceiverHandler);
		vTaskDelay( 1500 / portTICK_PERIOD_MS );
	}
}


void vTaskReceiver (void *pvParameter) {

	for(;;) {
		ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
		printf("Received notification\n");
	}
}
*/

void task1 (void *pvParameters) {
	for(;;) {
		printf("reading temperature from %s \n", (char *)pvParameters);
		vTaskDelay( 1000 / portTICK_PERIOD_MS);
	}
}

void task2 (void *pvParameters) {
	for(;;) {
		printf("reading humidity from %s \n", (char *)pvParameters);
		vTaskDelay( 1000 / portTICK_PERIOD_MS);
	}
}
void app_main(void)
{
	xTaskCreate(&task1, "vTaskSender", 2048, NULL, 2, NULL);
	xTaskCreate(&task2, "vTaskReceiver", 2048, NULL, 2, NULL);
}
