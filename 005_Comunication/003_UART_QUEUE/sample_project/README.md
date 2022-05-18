# UART QUEUE

- O processo é semelhante aos anterior com a diferença que na função de instalação do uart é informado uma queue 
    ~~~c
        uart_driver_install(UART_NUM_1, RX_BUF_SIZE, TX_BUF_SIZE, 20, &xUart_Queue, 0);
    ~~~

- É possivel fazer uso de reconhecimento de padrões com a função abaixo 
    ~~~c
        uart_enable_pattern_det_intr(UART_NUM_1, "+", PATTER_LEN, 10000, 10, 10);
    ~~~
    - Possui 6 parametros
        - UART da comunicação
        - caractere de padrão
        - numero de vezes que o caractere se repete 
        - intervalo de tempo para o padrão entre cada caractere 
        - timeout do ultimo caractere do padrão 
        - timeout do primeiro caractere do padrão 
