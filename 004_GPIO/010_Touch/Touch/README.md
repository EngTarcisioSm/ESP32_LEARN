# Touch

- Os sensores touch funcionam em apenas alguns pinos do esp32

- Para utilização do sensor deve-se incluir a biblioteca para uso:
~~~c
#include "driver/touch_pad.h"
~~~

- Para começar a trabalhar com o sensor é necessário inicializar o hardware atraves da função descrita abaixo 
~~~c
touch_pad_intr_clear();
~~~

- Após a inicialização do periférico é necessário configurar a tensão de operação do periférico, as parametros abaixo descrevem operações simples onde é configurada a operação em 2,7Volts com o toque sendo sentido a partir de 0,5Volts podendo ocorrer uma atenuação no sinal de 1volt
~~~c
touch_pad_set_voltage(TOUCH_HVOLT_2V7, TOUCH_LVOLT_0V5, TOUCH_HVOLT_ATTEN_0V5);
~~~

- o Proximo passo é selecionar o pino que irá trabalhar com o sensor touch atraves da função abaixo, que recebe o pino em questão juntamente com um segundo parametro indicando se é desejado algum timer sobre a ação do touch. Ao colocar -1 indica que não se deseja um timer sobre essa opção 
~~~c
touch_pad_config(TOUCH_PAD_NUM9, -1);
~~~

- Para ler o valor do sensor uma das funções possiveis de ser utilizada é a função abaixo que solicita o pino do sensor e um buffer atraves de ponteiro do tipo uint16_t
~~~c
touch_pad_read(TOUCH_PAD_NUM9, &u16Val)
~~~

- A biblioteca possui um filtro do tipo IRR, para isso é necessário também iniciar o filtro com a função abaixo que solicita como parametro o tempo de filtragem em ms, e a leitura é feita com uma função diferente que possui os mesmos parametros da de leitura da anterior 
~~~c
//função de inicialização do filtro
touch_pad_filter_start(10);
//função de leitura com o filtro iRR
touch_pad_read_filtered( TOUCH_PAD_NUM9, &u16Val1 );
~~~~

- Para ler o valor cru da leitura do sensor utiliza-se a função abaixo 
~~~c
touch_pad_read_raw_data( TOUCH_PAD_NUM9, &u16Val2 );
~~~