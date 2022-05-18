#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

xSemaphoreHandle xMutexBus;

void vWriteToBus(char *message) {
	xSemaphoreTake(xMutexBus, portMAX_DELAY);
	{
		printf(message);
	}
	xSemaphoreGive(xMutexBus);
}

void vTask1(void *pvParameters) {

	vWriteToBus("Task1 Start\n");
	for(;;) {
		vWriteToBus("temperature is 25C\n");
		vTaskDelay( 1000 / portTICK_PERIOD_MS );
	}
}

void vTask2(void *pvParameters) {

	vWriteToBus("Task1 Start\n");
	for(;;) {
		vWriteToBus("humidity is 50\%\n");
		vTaskDelay( 1500 / portTICK_PERIOD_MS );
	}
}

void app_main(void)
{
	xMutexBus = xSemaphoreCreateMutex();
	xTaskCreate(&vTask1, "temp reading", 2048, NULL, 2, NULL);
	xTaskCreate(&vTask2, "humidity reading", 2048, NULL, 2, NULL);
}
