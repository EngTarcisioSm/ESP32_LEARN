#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

xSemaphoreHandle xBinSemaphore;

void vTask_ListenForHTTP(void *pvParameters) {

	printf("Task Listen for http started!\n");
	for(;;) {
		printf("received http message\n");
		xSemaphoreGive( xBinSemaphore );
		vTaskDelay( 5000 / portTICK_PERIOD_MS );
	}
}

void vTask_Task1(void *pvParameters) {

	printf("Task1 started!\n");
	for(;;) {
		xSemaphoreTake( xBinSemaphore, portMAX_DELAY );
		printf("doing something with http\n");
	}
}


void app_main(void)
{
	xBinSemaphore = xSemaphoreCreateBinary();

	xTaskCreate(&vTask_ListenForHTTP, "get http", 2048, NULL, 1, NULL);
	xTaskCreate(&vTask_Task1, "do something with http", 2048, NULL, 1, NULL);
}
