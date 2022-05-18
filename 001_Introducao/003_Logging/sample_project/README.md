# LOGGING
- O esp32 vem com recursos de registro, possibilitando diferentes tipos de registro;
- Esses diferentes registros podem ser utilizados com base na biblioteca "esp_log.h"
- Todas as mensagens de registros s�o criadas atraves de fun��es com 2 parametros, o primeiro trata-se de uma tag e o
segundo da mensagem:
	- ESP_LOGE(): mensagem de erro
	- ESP_LOGW(): mensagem de aviso
	- ESP_LOGI(): mensagem de informa��o
	- ESP_LOGD(): mensagem de debug*
	- ESP_LOGV(): mensagem verbose*
		- (*) Por padr�o esses dois s�o desligados devendo ser ativados 
- Para habilita-la deve-se abrir o menuconfig do projeto 
	- Pega-se o caminho da pasta 
	- Abre-se o atalho do CMD da esp-idf 
	- Acesse a pasta desejada 
	- Insira o comando 
		- idf.py menuconfig<br>
	![imagem](img\001.png)
	- Ir em:
		Component config >> Log Output >> Default log verbosity >> (Selecione a Opção Verbose)
	- Feito o passo acima 
- É possivel habilitar também através da função abaixo, levando 2 parametros o primeiro é a TAG e o segundo é até qual deseja-se habilitar 
	~~~c
		esp_log_level_set("TAG", Define_de_mensa_a_ser_setada)
	~~~
	- Para funcionar todos os ESP_LOGx devem estar com a mesma tag
	~~~c
		esp_log_level_set("LOG", ESP_LOG_WARN);
		ESP_LOGE("LOG", "Isso é um erro!");
		ESP_LOGW("LOG", "Isso é um aviso!");
		ESP_LOGI("LOG", "Isso é uma informação!");
		ESP_LOGD("LOG", "Isso é uma mensagem de Debug!");
		ESP_LOGV("LOG", "Isso é um verbose");
	~~~