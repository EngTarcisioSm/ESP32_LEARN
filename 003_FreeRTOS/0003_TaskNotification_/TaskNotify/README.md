# Task Notification

- Para a criação de Task Notification é necessário um handler(manipulador)

- A função a dar o comando de take no TaskNotify tem de ter o handle TaskHandle_t em seu ultimo parametro da função de criação xTaskCreate
    - Esse handle deve ser passado tanto na função que vai escrever no handle como na função que irá ler o handle (o professor do curso errou nisso)

- Task Notification pode ser utilizado de diversas formas, neste exemplo serviu como despertador de uma tarefa adormecida, podendo operar também como um contador de ativação de tarefa pois o comantando take funciona como um incrementador do handle