#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

void app_main(void)
{
	gpio_config_t config;
	config.mode = GPIO_MODE_INPUT;
	config.intr_type = GPIO_INTR_POSEDGE;
	config.pull_down_en = 1;
	config.pull_up_en = 0;
	/* Caso varios pinos tenham a mesma configuração é possivel sinaliza-los todos aqui */
	config.pin_bit_mask = ((1ULL << GPIO_NUM_17) | (1ULL << GPIO_NUM_15));

	/*Função para a configuração utilizando a struct acima*/
	gpio_config(&config);




}
