#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/FreeRTOSConfig.h"

static TaskHandle_t xReceiverHandler = NULL;

void vTask1(void *pvParameter) {

	printf("Entrou vTask1\n");
	for (;;) {
		xTaskNotifyGive(xReceiverHandler);
		vTaskDelay(5000 / portTICK_PERIOD_MS);
	}
}

void vTask2(void *pvParameter) {

	printf("Entrou vTask2\n");
	for (;;) {
		ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
		printf("received notification\n");
	}
}

void app_main(void) {

	if ( xTaskCreate(&vTask1, "vTask1", 2048*2, NULL, 2, &xReceiverHandler) != pdTRUE ) {
		printf("falha 1\n");
	} else {
		printf("sucesso 1\n");
	}

	if( xTaskCreate(&vTask2, "vTask2", 2048*2, NULL, 2, &xReceiverHandler) != pdTRUE ) {
		printf("falha 2\n");
	} else {
		printf("sucesso 2\n");
	}

}

