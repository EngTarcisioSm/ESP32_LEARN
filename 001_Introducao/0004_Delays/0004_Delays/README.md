# Delays 

- É possivel utilizar a função vTaskDelay() do freeRTOS para gerar delays
- Bibliotecas utilizadas
    ~~~c
        #include "freertos/FreeRTOS.h"
        #include "freertos/task.h"  
    ~~~
- Após o procedimento basta chamar a função vTaskDelay()
    - o valor do delay inserido como parametro deve ser dividido por "portTICK_PERIOD_MS" para se gerar o tempo em milissegundos 