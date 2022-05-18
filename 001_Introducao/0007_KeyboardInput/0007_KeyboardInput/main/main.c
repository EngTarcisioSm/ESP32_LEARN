#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
	char cCharInput = 0;
	char acCharArray[100];

	//limpeza do buffer
	memset(acCharArray, 0x00, sizeof(acCharArray));

	//fica em modo captura até que uma quebra de linha "\n" ocorra
	while(cCharInput != '\n') {
		cCharInput = getchar();
		if(cCharInput != 0xFF) {
			acCharArray[strlen(acCharArray)] = cCharInput;
			printf("%c", cCharInput);
		}
		vTaskDelay( 100 / portTICK_PERIOD_MS );
	}
	printf("sua escrita: %s\n", acCharArray);

}
