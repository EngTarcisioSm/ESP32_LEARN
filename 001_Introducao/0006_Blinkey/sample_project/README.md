# Blinkey

- Para a utilização dos pinos como entradas ou saídas digitais e ou analógica, é necessário efetuar a configuração 
- É necessário para esse processo chamar uma biblioteca 
    ~~~c
        #include "driver/gpio.h"
    ~~~
- Duas funções são necessárias para a configuração do pino
    ~~~c
        gpio_pad_select_gpio(att1); //att1 refere-se ao pino 
        gpio_set_direction(att2, att3); //att2 referece ao pino configurado e att2 ao estado dele
                                        //criado por um define da propria biblioteca
    ~~~
    - A primeira função aparenta não ser mais utilizada

- Escrita digital em GPIO
    ~~~c
        gpio_set_level(att1, att2);     //att1: pino att2: status do pino
    ~~~