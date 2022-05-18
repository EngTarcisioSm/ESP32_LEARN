# High Resolution Timer

- Uma das principais desvantagens do timer do FreeRTOS é que sua resolução minima dependendo de configurações efetuadas no arquivo header de configuração, fica em torno de 1ms 

- A segunda desvantagem é que a função de callback do timer possui uma prioridade muitissimo baixa

- A idf do esp possui como API um timer de alta resolução

- Para a utilização do timer é necessário incluir a biblioteca 
    ~~~c
        #include "esp_timer.h"
    ~~~

- Para inicializar o timer é necessário criar uma struct (esp_timer_create_args_t) que ja esta criada, a struct necessita de vários parametros, entretanto para operação simples apenas dois são necessários, .callback, que é uma função de retorno fornecida para a struct do tipo void e um nome para timer no atributo .name

- É necessário criar um handle para o timer do tipo "esp_timer_handle_t"

- Para criar o timer é necessário utilizar a função esp_timer_create que possui dois parametros
    - ponteiro para a struct esp_timer_create_args_t
    - poteito para o handle esp_timer_handle_t

- Para inicializar o timer existe duas formas distintas de se fazer que são utilizando duas funções distintas 

- Inicializar timer de disparo unico:
    - Função: esp_timer_start_once(), dois parametros 
        - handle do timer   
        - tempo de estouro do timer passado em us (microsseundos)

    - Função: esp_timer_start_period()


- *Existe um limitante no tempo minimo para execução de disparo unico de 20us e para disparos periodicos que é de 50us*
    - Existe formas de se obter tempos inferiores a estes citados entretanto necessita de lógicas diferentes 

- É possivel parar o timer com a função esp_timer_stop() que tem como parametro o handle do Timer 

- É possivel deletar o tiper com a função esp_timer_delete() que tem como parametro o handle do timer 

- A função esp_timer_dump() com o parametro  stdout printa o estouro do timer na serial 


- Conteudo adiantado (utilizando GPIOS)

    - Utilizar a biblioteca "driver/gpio.h

    - Selecionar o gpio que será utilizado atraves da função gpio_pad_select_gpio()
        - recebe como parametro o numero do gpio a ser utilizado atraves de um define presente ja na biblioteca GPIO_NUM_? onde ? é o numero do gpio
    - Selecionar se o gpio será de entrada ou saida atraves da função gpio_set_direction() que possui dois parametros 
        - o gpio que será configurado  utilizando o define GPIO_NUM_?
        - o Modo de operação também configuravel atraves de defines da biblioteca GPIO_MODE_?
    - Na situação de escrita em um gpio, utilizar a função gpio_set_level() que possui dois parametros 
        - o gpio em que se irá escrever atravez dos defines GPIO_NUM_?
        - um booleano do estado do gpio