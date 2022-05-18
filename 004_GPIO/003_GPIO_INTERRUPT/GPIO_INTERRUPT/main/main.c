#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#define PIN_SWITCH GPIO_NUM_17

xQueueHandle xInterruptQueue;

/**
 * @brief Função de callback da interrupção de gpio
 * 
 * @param args informa o pino em que ocorreu a interrupção
 */
static void IRAM_ATTR gpio_isr_handler(void *args) {

	int pinNumber = (int)args;
	/* Como esta dentro de uma fun��o de interrup��o se usar  ao tratar de freertos
	 * deve-se utilizar as fun��es terminadas en ISR */
	xQueueSendFromISR(xInterruptQueue, &pinNumber, NULL);
}

/**
 * @brief 
 * 
 */
void vConfigPinSwitch(void) {

	//seleciona pino de configura��o
	gpio_pad_select_gpio(PIN_SWITCH);

	/* Configura Pino como um pino habilidado para recebimento de interrup��o */
	gpio_set_direction(PIN_SWITCH, GPIO_MODE_INPUT);

	// habilita o resistor de pulldown
	gpio_pulldown_en(PIN_SWITCH);

	// desabilita o pino de pullup
	gpio_pullup_dis(PIN_SWITCH);

	/* Habilita como a interrup��o ocorrer� neste caso na detec��o de borda de subida*/
	gpio_set_intr_type(PIN_SWITCH, GPIO_INTR_NEGEDGE);

	/* instala o servi�o de interrup��o inserindo a flag */
	gpio_install_isr_service(0);

	/* Adiciona a interrup��o, necessita de tr�s parametros, o pino que sobre a interrup��o
	 * a fun��o de callback para a tratativa e um parametro que vem a ser o pino da interrup��o
	 * novamente????
	 */
	gpio_isr_handler_add(PIN_SWITCH, gpio_isr_handler, (void *)PIN_SWITCH);
}

/**
 * @brief 
 * 
 * @param pvParameters 
 */
void vTask_ButtomPushedTask(void *pvParameters){

	int iPinNumber, count = 0;

	printf("Task started\n");
	for(;;) {
		if( xQueueReceive(xInterruptQueue, &iPinNumber, portMAX_DELAY) ) {
			printf("GIPIO %d was pressed %d times. The sate is %d \n", iPinNumber, count++, gpio_get_level(PIN_SWITCH));
		}
	}
}

void app_main(void)
{
	xInterruptQueue = xQueueCreate(10,sizeof(int));

	xTaskCreate(&vTask_ButtomPushedTask, "ButtomPushedTask", 2048, NULL, 1, NULL);

	vConfigPinSwitch();


}


