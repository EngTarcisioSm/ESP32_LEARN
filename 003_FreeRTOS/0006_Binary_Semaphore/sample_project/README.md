# Semáforo Binário

- Semáforos Binários são muito semelhantes a mutex;

- Semáforos binários geralmente são utilizados para indicar que algo ocorreu;

- Para criar um semáforo binário utiliza-se a função "xSemaphoreCreateBinary()" não possui atributos e possui retorno no handle que deve ser criado 

- A função xSemaphoreGive recebe como parametro o semáforo inserindo uma tag no semáforo (que pode receber apenas um)

- A função xSemaphoreTake remove a tag que foi inserida no semaforo, recebe como parametro dois atributos, o primeiro é o semaforo no qual será retirado o valor e o segundo vem a ser o tempo de espera 

- No exemplo do código utilizado o semaforo esta servido de parametro para a Task1 ser executada, pois a mesma so executa seus processos caso uma tag tenha sido inserida pela task de recebimento http

- Se a task1 tivesse maior prioridade que a task do http ocorreria que assim que a tag fosse inserida o contexto seria dado a task1 ser execudada para posterior finalização da task http 
