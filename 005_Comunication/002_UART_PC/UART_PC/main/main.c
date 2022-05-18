#include <stdio.h>
#include "esp_log.h"
#include "driver/uart.h"
#include "string.h"

#define TXD_PIN			4
#define RXD_PIN			5

#define RX_BUFFER_SIZE	1024


void app_main(void)
{
	char message[] = "ping";
	char recieve[RX_BUFFER_SIZE];

	uart_config_t uart_config = {
			.baud_rate = 9600,
			.data_bits = UART_DATA_8_BITS,
			.parity = UART_PARITY_DISABLE,
			.stop_bits = UART_STOP_BITS_2,
			.flow_ctrl = UART_HW_FLOWCTRL_DISABLE
	};


	uart_param_config(UART_NUM_1, &uart_config);

	uart_set_pin(UART_NUM_1, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

	uart_driver_install(UART_NUM_1, RX_BUFFER_SIZE, 0, 0, NULL, 0);

	printf("sending: %s\n", message);
	uart_write_bytes(UART_NUM_1, message, sizeof(message));

	while(true) {
		memset(recieve, 0x00, sizeof(recieve));
		uart_read_bytes(UART_NUM_1, recieve, RX_BUFFER_SIZE, pdMS_TO_TICKS(500));
		printf("received: %s\n", recieve);
	}
}
