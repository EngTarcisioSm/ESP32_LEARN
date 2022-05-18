#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define TAG	"DELAY"

void app_main(void)
{
	uint32_t aux = 0x00;

	while(1) {
		vTaskDelay( 1000 / portTICK_PERIOD_MS);
		ESP_LOGI(TAG, "Valor: %d", aux++);
	}
}

