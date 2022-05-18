#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static TaskHandle_t xReceiverHandle = NULL;

void vTask_Sender(void *pvParameters) {

	for(;;) {
		xTaskNotify( xReceiverHandle, ( 1 << 0 ), eSetBits );
		vTaskDelay( 1000 / portTICK_PERIOD_MS);
		xTaskNotify( xReceiverHandle, ( 1 << 1 ), eSetBits );
		vTaskDelay( 1000 / portTICK_PERIOD_MS);
		xTaskNotify( xReceiverHandle, ( 1 << 2 ), eSetBits );
		vTaskDelay( 1000 / portTICK_PERIOD_MS);
		xTaskNotify( xReceiverHandle, ( 1 << 3 ), eSetBits );
		vTaskDelay( 1000 / portTICK_PERIOD_MS);
	}
}

void vTask_Receiver(void *pvParameters) {

	uint32_t ucState;
	for(;;) {
		xTaskNotifyWait(0, 0xFFFFFFFF, &ucState, portMAX_DELAY);
		printf("received state: %d\n", ucState);
	}
}






void app_main(void)
{
    xTaskCreate(&vTask_Sender, "sender", 2048, NULL, 2, &xReceiverHandle);
    xTaskCreate(&vTask_Receiver, "receiver", 2048, NULL, 2, &xReceiverHandle);
}
