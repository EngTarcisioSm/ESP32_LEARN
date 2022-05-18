#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"

EventGroupHandle_t xEvent;

const EventBits_t xgotHttp = BIT0;
const EventBits_t xgotBLE = BIT1;


void vTask_ListenForHttp(void *pvParameters) {

	printf("ListenForHttp started...\n");
	for(;;) {

		xEventGroupSetBits(xEvent, xgotHttp);
		printf("got http\n");
		vTaskDelay( 2000 / portTICK_PERIOD_MS );
	}
}


void vTask_listenForBluetooth(void *pvParameters) {

	printf("ListenBluetooth started...\n");
	for(;;) {

		xEventGroupSetBits(xEvent, xgotBLE);
		printf("got bluetooth\n");
		vTaskDelay( 5000 / portTICK_PERIOD_MS );
	}
}


void vTask_Task1(void *pvParameters) {

	printf("Task1 started...\n");
	for(;;) {

		xEventGroupWaitBits(xEvent, xgotBLE | xgotHttp, true, true, portMAX_DELAY);
		printf("received http and BLE\n");
	}
}


void app_main(void)
{
	xEvent = xEventGroupCreate();

	xTaskCreate(&vTask_ListenForHttp, "ListenForHttp", 2048, NULL, 1, NULL);
	xTaskCreate(&vTask_listenForBluetooth, "listenForBluetooth", 2048, NULL, 1, NULL);
	xTaskCreate(&vTask_Task1, "Task1", 2048, NULL, 1, NULL);
}
