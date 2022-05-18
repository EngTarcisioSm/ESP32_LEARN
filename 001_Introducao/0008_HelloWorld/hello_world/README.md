# Hello World

- Tras informações do chip

- Bibliotecas 
~~~c
#include "esp_system.h"     //funções a respeito do chip
#include "esp_spi_flash.h"  //funções a respeito da memoria flash do chip
~~~

- A memória flash é conectada pelo chip atraves de comunicação SPI

- Estrutura 
~~~c
esp_chip_info_t chip_info; //struct que armazena informações do chip
~~~
    - Definições:
~~~c
    typedef struct {
        esp_chip_model_t model;  //modelo do chip
        uint32_t features;       //recursos do chip sinalizados por cada bit 
        uint8_t cores;           //numero de nucleos
        uint8_t revision;        //número da revisão
    } esp_chip_info_t;
~~~

- NO programa informa uma quantidade de memória disponivel de 2mb, isso ocorre pois para configurar as demais quantidades de memoria é necessário efetuar uma configuração 

- Descobrir versão da idf que esta sendo executada
~~~c
    esp_get_idf_version();  //retorna uma string com informações
~~~
    - É importante pois algumas bibliotecas mudam conforme  versão da idf podendo fazer ocorrer erros caso haja a atualização da idf e não do código

- Visualizar numero MAC Address
~~~c
//necessario criar um buffer 
uint8_t chipID[6];
esp_efuse_mac_get_default(chipID);
printf("mac / chip id: %02x%02x%02x%02x%02x%02x\n", chipID[0], chipID[1], chipID[2], chipID[3], chipID[4], chipID[5]);
~~~