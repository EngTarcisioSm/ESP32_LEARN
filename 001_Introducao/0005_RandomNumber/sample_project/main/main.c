#include <stdio.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "math.h"

#define TAG	"Dado"

void app_main(void) {
	while (1) {
		int random = esp_random();
		int positiveNumber = abs(random);
		int dadoNumero = (positiveNumber % 6) + 1; //fará com que o intervalo de numeros fique de 0 a 5

		vTaskDelay(1000 / portTICK_PERIOD_MS);
		ESP_LOGI(TAG, "random number is %d", dadoNumero);
	}
}
