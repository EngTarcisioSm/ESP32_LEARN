# Mutex
- Utilizado para gerenciar algum processo do microcontrolador (i2c, uart, etc...);

- Mutex são semáforos binários;

- Para a utilização de semáforos pe necessário chamar a biblioteca semph.

- Para criar um semáforos é necessiáro ter um Handle

- é necessário criar o objeto mutex com a função "xSemaphoreCreateMutex()

- Mutex funciona como um semáforo onde há uma flag na qual permite gerenciar um recurso

- xSemaphoreTake tem por objetivo fornecer a flash e possui dois parametros, o primeiro refere-se a mutex na qual se ira pegar a flag e o segundo parametro é o tempo de espera 

- xSemaphoreGive tem por objetivo devolver a flag a mutex tendo como parametro apenas o nome da mutex que deve ser devolvida a flag 