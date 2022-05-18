# GPIO OUTPUT 

- Ao utilizar os gpios do microcontrolador o consumo de corrente eletrica não pode exceder 20mA, isso quando utilizando apenas 1 pino e quando utilizando mais de um não pode exceder 40mA.

- Utilizando GPIOS

    - Utilizar a biblioteca "driver/gpio.h

    - Selecionar o gpio que será utilizado atraves da função gpio_pad_select_gpio()
        - recebe como parametro o numero do gpio a ser utilizado atraves de um define presente ja na biblioteca GPIO_NUM_? onde ? é o numero do gpio
    - Selecionar se o gpio será de entrada ou saida atraves da função gpio_set_direction() que possui dois parametros 
        - o gpio que será configurado  utilizando o define GPIO_NUM_?
        - o Modo de operação também configuravel atraves de defines da biblioteca GPIO_MODE_?
    - Na situação de escrita em um gpio, utilizar a função gpio_set_level() que possui dois parametros 
        - o gpio em que se irá escrever atravez dos defines GPIO_NUM_?
        - um booleano do estado do gpio


- Para ativação de cargas maiores é necessário um circuito externo 
    - Um componente indicado pelo professor é o IRLML2502PbF que pode fornecer até 20V e 4A ( com corrente acima de 1A é necessário dissipador apropriado)