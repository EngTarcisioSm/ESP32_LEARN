#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"


/*
 * Exemplo 1
 */

//xQueueHandle xQueueTest;
//
//void vTask_ListenForHttp(void *pvParameters) {
//
//	int count = 0;
//
//	for (;;) {
//		count++;
//		printf("received http message\n");
//
//		BaseType_t xOkQueue = xQueueSend(xQueueTest, &count,
//				1000 / portTICK_PERIOD_MS);
//
//		if(xOkQueue) {
//			printf("added message to queue\n");
//		} else {
//			printf("failed to add messager to queue\n");
//		}
//
//		vTaskDelay( 5000 / portTICK_PERIOD_MS );
//
//	}
//}
//
//void vTask_Task1(void *pvParameters) {
//
//	for (;;) {
//		printf("doing something with http\n")
//	}
//}
//
//void app_main(void) {
//
//	xQueueTest = xQueueCreate(3, sizeof(int));
//	xTaskCreate(&vTask_ListenForHttp, "Http Send", 2048, NULL, 2, NULL);
//	//xTaskCreate(&vTask_Task1, "Task1", 2048, NULL, 2, NULL);
//}

/******************************************************************************/

/*
 * Exemplo 2
 */
xQueueHandle xQueueTest;

void vTask_ListenForHttp(void *pvParameters) {

	int count = 0;

	for (;;) {
		count++;
		printf("received http message\n");

		BaseType_t xOkQueue = xQueueSend(xQueueTest, &count,
				1000 / portTICK_PERIOD_MS);

		if(xOkQueue) {
			printf("added message to queue\n");
		} else {
			printf("failed to add messager to queue\n");
		}

		vTaskDelay( 1000 / portTICK_PERIOD_MS );

	}
}

void vTask_Task1(void *pvParameters) {

	int iReceiver;
	for (;;) {

		if (xQueueReceive(xQueueTest, &iReceiver, 5000 / portTICK_PERIOD_MS) ) {
			printf("doing something with http %d\n", iReceiver);
		} else {
			//
		}

	}
}

void app_main(void) {

	xQueueTest = xQueueCreate(3, sizeof(int));
	xTaskCreate(&vTask_ListenForHttp, "Http Send", 2048, NULL, 2, NULL);
	xTaskCreate(&vTask_Task1, "Task1", 2048, NULL, 2, NULL);
}



