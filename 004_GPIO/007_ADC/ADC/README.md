# ADC

- Existem dois  ADC no esp32 que podem ser utilizados; 
- O primeiro ADC possui 8 canais e o segundo possuindo 10 canais;
    - Existem certas restrições em alguns canais;
    - O segundo canal possui drivers que são utilizados pelo wifi, logo apenas um pode estar em uso por vez, ou o adc2 ou o wifi
    - No primeiro adc os canais sobre os gpios 36 e 39 são utilizados também para sensore internos, logo apenas use esses pinos caso não esteja utilizando os sensores internos

- O primeiro passo é incluir a biblioteca 
~~~c
    #include "driver/adc.h"
~~~

- O segundo passo é definir a quantidade de bits a do adc a partir da função abaixo (pode-se configurar 9, 10, 11 ou 12 bits)
~~~c
    //função para o adc1
    adc1_config_width(ADC_WIDTH_BIT_12);
~~~
- O proximo passo é configurar é o fundo de escala do adc, através da função abaixo que pede o canal utilizado (gpio onde será lido) e o fundo de escala que possui diversos valores possiveis 

- Para efetuar a leitura utiliza-se a função abaixo que requer apenas o canal a ser lido 