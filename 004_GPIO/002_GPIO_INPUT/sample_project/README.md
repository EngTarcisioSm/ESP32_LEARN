# GPIO INPUT

- O modo input o pino estará recebendo um nivel logio 1 (3v3 para esp32) ou 0.

- O modo de configuração é similar 

- Código de ativação em modo input 
    ~~~c
        gpio_pad_select_gpio(PIN_SWITCH);
        gpio_set_direction(PIN_SWITCH, GPIO_MODE_INPUT);
    ~~~


- É possivel caso necessário configurar resistores de pullup ou pulldown internos atraves das funções 
    ~~~c
        gpio_pulldown_en(parametro);    //parametro é o pino a ser habilitado
        gpio_pullup_en(parametro);    //parametro é o pino a ser habilitado
    ~~~

- Uma observação deve ser feita ao trabalhar com gpios quando selecionar uma porta caso não esteja utilizando resistores internos de pullup ou pulldown é recomendavel desativa-los via código, pois não fazer isso pode acarretar em problemas. No caso de não utilizar nenhum, desativar os dois, caso esteja utilizando um deles, desativar o outro. A desabilitação é feita através da função 
    ~~~c
        gpio_pulldown_dis(parametro);   //desabilita o resistor de pulldown do pino passado como parametro
        gpio_pullup_dis(parametro);   //desabilita o resistor de pullup do pino passado como parametro
    ~~~