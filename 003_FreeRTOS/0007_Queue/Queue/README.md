# Queue

- Queues são muito similares a Semaphores com a diferença que podem transmitir e receber dados;

- Para se criar uma Queue, é necessário criar um Handle de queue do tipo "xQueueHandle", seguido a isso é necessário inicializar a fila que tera o seu ojeto apontado pelo handle acima com a função xQueueCreate. Essa função recebe 2 parametros, o primeiro se refere ao tamanho da fila, ou seja quantos itens ela comportará e o segundo refere-se ao tamanho do tipo que será armazenado.

- Para o envio de dados através da queue utiliza-se a função xQueueSend(), que possui 3 parametros:
    - Parametro 1: handle da queue que será escrito
    - Parametro 2: ponteiro da variavel que armazerna o valor a ser enviado 
    - Parametro 3: tempo de espera para a escrita na queue 

- No Exemplo 1 a Queue é preenchido até que não se possa mais escrever sobre a mesma 

- Para receber dados de uma Queue utiliza-se a função xQueueReceive que possui os mesmos parametros da de envio, com a diferença que ela não aguarda o tempo de escrita mais sim o tempo para ler algum dado 

- No exemplo2 a task1 consome a queue, lendo os dados