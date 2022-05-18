#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

/******************************************************************************/
/* DEFINES */
#define PIN_SWITCH	GPIO_NUM_17

/******************************************************************************/
/* VARIABLES */
xQueueHandle xInterruptQueue;

/******************************************************************************/
/* PROTOTYPES */
static void IRAM_ATTR vISR_GPIO_Handle(void *args);

void vConfig_Pin_Switch(void);
void vInstall_Queues_FreeRTOS(void);
void vInstall_Tasks_FreeRTOS(void);

/* TASKS */
void vTask_DebounceSwitch(void *pvParameters);

/******************************************************************************/
/* MAIN PROGRAM */
void app_main(void) {
	vInstall_Queues_FreeRTOS();
	vInstall_Tasks_FreeRTOS();

	vConfig_Pin_Switch();

}

/******************************************************************************/
/* FUNCTIONS */

/**
 * @brief Fun��o de callback da interrup��o de gpio
 *
 * @param args informa o pino em que ocorreu a interrup��o
 */
static void IRAM_ATTR vISR_GPIO_Handle(void *args) {

	uint8_t ucPinNumber = (uint8_t) args;

	xQueueSendFromISR(xInterruptQueue, &ucPinNumber, NULL);
}

/**
 * @brief Configura o pino e habilita interrup��o em borda de descida
 *
 */
void vConfig_Pin_Switch(void) {

	/* Seleciona o pino de configura��o */
	gpio_pad_select_gpio(PIN_SWITCH);
	/* Configura o pino selecionado como um pino input */
	gpio_set_direction(PIN_SWITCH, GPIO_MODE_INPUT);
	/* Habilita o resistor de pulldown */
	gpio_pulldown_en(PIN_SWITCH);
	/* Desabilitar o resistor de pullup */
	gpio_pullup_dis(PIN_SWITCH);
	/* Configura a interrup��o para ocorrer em borda de descida */
	gpio_set_intr_type(PIN_SWITCH, GPIO_INTR_POSEDGE);
	/* Instalar o servi�o de interrupcao inserindo flag */
	gpio_install_isr_service(0);
	/* Aciona interrupcao, com tres parametros:
	 * - pino de interrupcao
	 * - funcao de callback
	 * - parametro passado para funcao de callback(pino que ocorreu a interrupcao)
	 */
	gpio_isr_handler_add(PIN_SWITCH, vISR_GPIO_Handle, (void*) PIN_SWITCH);
}

/**
 * @brief Instala queues de utiliza��o do sistema FreeRTOS
 *
 */
void vInstall_Queues_FreeRTOS(void) {
	xInterruptQueue = xQueueCreate(2, sizeof(uint8_t));
}

/**
 * @brief Instala tasks de utiliza��o do sistema FreeRTOS
 *
 */
void vInstall_Tasks_FreeRTOS(void) {
	xTaskCreate(&vTask_DebounceSwitch, "DebounceSwitch", 2048, NULL, 1, NULL);
}

/******************************************************************************/
/* TASKS */

/**
 * @brief Task para gerenciamento de bot�o e tratativa de debounce
 *
 * @param pvParameters sem uso
 */
void vTask_DebounceSwitch(void *pvParameters) {

	uint8_t ucPinNumber, ucCount = 0, ucCountButtom = 0;
	for (;;) {

		/* Recebimento da Queue de Interrup��o */
		if (xQueueReceive(xInterruptQueue, &ucPinNumber, portMAX_DELAY)) {
			/* Desabilita a interrup��o */
			gpio_isr_handler_remove(ucPinNumber);

			/* espera algum tempo para checar se o bot�o ainda esta pressionado */
			do {

				vTaskDelay(100 / portTICK_PERIOD_MS);
				/* No Caso o bot�o fica constantemente em nivel 0 e � ativo em 1 */
				ucCount++;
			} while (gpio_get_level(ucPinNumber) == 1);

			/* fazer o trabalho que deve */
			if (ucCount < 20) {
				ucCount = 0;
				printf("GPIO %d was pressed %d times. The State is %d\n",
						ucPinNumber, ucCountButtom++,
						gpio_get_level(ucPinNumber));
			} else {
				ucCountButtom = 0;
				ucCount = 0;
				printf("Buttom RESETED\n");
			}


			/* reabilitar a interrup��o */
			gpio_isr_handler_add(ucPinNumber, vISR_GPIO_Handle, (void *)ucPinNumber );
		}

	}
}

