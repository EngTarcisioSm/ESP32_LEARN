# Timers do FreeRTOS

- O FreeRTOS possui timers internos que podem ser utilizados em determinadas situações;

- As bibliotecas para utilizar os timers do freertos são as descritas abaixo 
    ~~~c
        #include "freertos/FreeRTOS.h"
        #include "freertos/timers.h"
    ~~~

- A biblioteca abaixo tem como um dos objetos retornar o tempo em microsegundos desde que o microcontrolador foi iniciado  
    ~~~c
        #include "esp_system.h"
    ~~~
    - O tempo pode ser obtido pela função esp_timer_get_timer()

- Para criar o timer utiliza-se a função xTimerCreate() que possui 5 parametros 
    - string com o nome do timer 
    - tempo do timer informado atravez da matro pdMS_TO_TICKS(tempo_em_ms)
    - bool se o timer se repete ou nao
    - ID do timer 
    - função de callback que será chamada toma vez que o timer tiver seu estouro 
        - A função de callback deve ter como parametro o handle do timer 
        - Em funções de call back não se deve ter nada bloqueante como delays 

- Após criado o timer é necessário inicia-lo com a função xTimerStart que possui dois parametros 
    - O handle do timer a ser inicializado 
    - Possivel delay para que o timer seja inicializado  



