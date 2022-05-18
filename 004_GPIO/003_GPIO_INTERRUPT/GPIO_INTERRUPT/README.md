# Interrupção

- Obedece a mesma logica de qualquer microcontrolador 

- Configuração da interrupção no esp32

    ~~~c
    //seleciona pino de configuração
	gpio_pad_select_gpio(PIN_SWITCH);					
	
	/* Configura Pino como um pino habilidado para recebimento de interrupção */
	gpio_set_direction(PIN_SWITCH, GPIO_MODE_INPUT);	
	
	// habilita o resistor de pulldown
	gpio_pulldown_en(PIN_SWITCH);						
	
	// desabilita o pino de pullup
	gpio_pullup_dis(PIN_SWITCH);						

	/* Habilita como a interrupção ocorrerá neste caso na detecção de borda de subida*/
	gpio_set_intr_type(PIN_SWITCH, GPIO_INTR_POSEDGE);	
	
	/* instala o serviço de interrupção inserindo a flag */
	gpio_install_isr_service(0);						
	
	/* Adiciona a interrupção, necessita de três parametros, o pino que sobre a interrupção
	 * a função de callback para a tratativa e um parametro que vem a ser o pino da interrupção
	 * novamente????
	 */
	gpio_isr_handler_add(PIN_SWITCH, gpio_isr_handler, (void *)PIN_SWITCH);
    ~~~

- A função de callback de interrupção possui um prefixo antes de seu nome "IRAM_ATTR" que sinaliza que a função deve ser alocaca na regi~]ao de DRAM do microcontrolador 
    - Quando se utiliza funções dentro das memorias dinamicas, muitas coisas podem passar a não funcionar, desta forma é recomendado fazer a menor quantidade de coisas possiveis dentro da mesma
    - Criar ou invocar task funciona 
    - Manipular semáforos funciona 
    - Manipular Queues




- OBSERVAÇÔES INTERESSANTES 
    - É possivel criar parametros para funções que não possi tipo definido e dentro da função trabalhar esse tipo