# Event Group

- São muito similares a semaforos, com a diferença que podem operar multiplos indicadores.

- Diferente dos semaforos que tem como função um simples start ou stop, os semaforos podem ter multiplos eventos 

- O primeiro passo para utilizar os eventgroups e incluir a biblioteca apropriada 
    ~~~c
        #include "freertos/event_groups.h"
    ~~~

- O segundo é necessário criar um handle de event_group
    ~~~c
        EventGroupHandle_t xEvent;
    ~~~

- Para criar o event group utiliza-se a função xEventGroupCreate(), que não possui parametros e tem como retorno a handle criada 
    ~~~c
        xEvent = xEventGroupCreate();
    ~~~

- O event group trabalha com acionamento de bits. Existe dentro da lib de eventgroups defines para cada bit possivel de acionamento (aparentemente de BIT0 a BIT23)

- A função xEventGroupSetBits() recebe dois parametros o primeiro é o eventgroup que será setado o bit e o segundo parametro são os bits a serem acionados 

- A função xEventGroupWaitBits() tem como objeto obter os bits que estão acionados, possuindo ao todo 5 parametros:
    - O nome do handle do event group
    - O bit ou bits (em logica ou) que deseja aguardar 
    - Limpar ou não os bits a serem lidos? bool
    - Esperar por todos os bits selecionados? bool
    - Tempo de espera 

