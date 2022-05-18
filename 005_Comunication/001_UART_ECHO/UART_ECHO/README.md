# Comunicação Serial Buffer

## Pasoss

- A primeira coisa para se utilizar a comunicação serial é a inclusão de sua respectiva biblioteca para uso
    ~~~c
    #include "driver/uart.h"
    ~~~

- Criar struct de configuração do tipo "uart_config_t
    ~~~c
        uart_config_t uart_config = {
                .baud_rate = 9600,
                .data_bits = UART_DATA_8_BITS,
                .parity = UART_PARITY_DISABLE,
                .stop_bits = UART_STOP_BITS_2,
                .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
        };
    ~~~
    
- Inserir a configuração efetuada na UART escolhida (o esp32 possui 3)
    ~~~c
    uart_param_config(UART_NUM_1, &uart_config);
    ~~~

- Configurar os pinos a serem utilizados pela UART 
    ~~~c
    uart_set_pin(UART_NUM_1, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    ~~~
        - Recebe 5 parametros 
            - A uart de configuração 
            - numero do pino de tx
            - numero do pino de rx
            - numero do pino de rts (pode não ser utilizado nesse caso colocar a constante "UART_PIN_NO_CHANGE")
            - numero do pino de cst (pode não ser utilizado nesse caso colocar a constante "UART_PIN_NO_CHANGE")
    
- Efetuar a instalação do canal uart
    ~~~c
        uart_driver_install(UART_NUM_1, RX_BUFFER_SIZE, 0, 0, NULL, 0);
    ~~~
        - Recebe 6 parametros
            - A Uart de configuração
            - O tamanho do buffer de RX
            - O Tamanho do buffer de TX
            - O tamanho da queue 
            - O ponteiro para a queue 
            - A flag de interrupção

- O envio de mensagens pode ser feito pela função abaixo 
    ~~~c
        uart_write_bytes(UART_NUM_1, message, sizeof(message));
    ~~~
        - Recebe 3 parametros
            - A uart de comunicação 
            - O Buffer contendo a mensagem a ser enviada 
            - O tamanho da mensagem a ser enviada

- O recebimento de mensagens pode ser feito pela função abaixo 
    ~~~c
        uart_read_bytes(UART_NUM_1, recieve, RX_BUFFER_SIZE, pdMS_TO_TICKS(500));
    ~~~
        - Recebe 3 parametros 
            - A uart de comunicação 
            - O buffer de recebimento 
            - O tamanho do buffer de recebimento
            - Configuração de timeout


