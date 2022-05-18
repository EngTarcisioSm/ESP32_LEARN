# PWM

- É possivel gerar sinais de pwm no ESP32

- Para a geração é necessário configurar 2 estruturas
    - Na primeira estrutura é selecionado o timer a ser utilizado (o esp32 possui 16 timer sendo 8 rápidos e 8 lentos), seguido a isso a frequencia que também é configurado 
    - Na segunda estrutura é configurado o canal (existindo 16 possiveis), a porcentagem do dutycycle e a associação com o timer criado 

- Para gerar o pwm é necessário utilizar a biblioteca 
~~~c
    #include "driver/ledc.h"
~~~

- após isso é necessário configurar a struct ledc_timer_config_t em todos seus parametro 
~~~c
ledc_timer_config_t timer = {
			.speed_mode = LEDC_LOW_SPEED_MODE,
			.duty_resolution = LEDC_TIMER_10_BIT,
			.timer_num = LEDC_TIMER_0,
			.freq_hz = 5000,
			.clk_cfg = LEDC_AUTO_CLK
	};
~~~
- Após a configuração é necessário passar a struct como parametro para a função abaixo para que a configuração seja efetuada no timer
~~~c
ledc_timer_config(&timer);
~~~
- Após essa configuração é necessário configurar a segunda struct chamada de ledc_channel_config_t, configurando os parametros gpio_num, speed_mode, channel, timer_sel, duty e hpoint
~~~c
ledc_channel_config_t channel = {
			.gpio_num = 4,                   			/*!< the LEDC output gpio_num, if you want to use gpio16, gpio_num = 16 */
			.speed_mode = LEDC_LOW_SPEED_MODE,          /*!< LEDC speed speed_mode, high-speed mode or low-speed mode */
			.channel = LEDC_CHANNEL_0,         			/*!< LEDC channel (0 - 7) */
			.timer_sel = LEDC_TIMER_0,         			/*!< Select the timer source of channel (0 - 3) */
			.duty = 1,                  				/*!< LEDC channel duty, the range of duty setting is [0, (2**duty_resolution)] */
			.hpoint = 0
	};
~~~
- Após a configuração da segunda estrutura é necessário passa-la como parametro para a função abaixo 
~~~c
ledc_channel_config(&channel);
~~~

- É possivel alterar o dutycycle em tempo de execução ao longo do código atraves da função ledc_set_duty, que recebe 3 parametros, o modo de velocidade, o canal e o novo valor do dutycycle. Após isso é necessário utilizar a função de atualização ledc_update_duty que recebe dois parametros, o modo de velocidade e o canal 
~~~c
ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, i);
ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
~~~

- É possivel fazer o processo de atualização no loop com apenas uma unica função, instalando a função de led com a função 
~~~c
    led_fade_func_install(0); //o 0 representa a flag que pode ser utilizada para insterrupção 
~~~

- A partir disso basta utilizar a função abaixo que recebe os parametros de tipo de velocidade, canal o novo duty e o valor do hpoint

- Existe ainda a função led_set_fade_time_and_start através da qual é possivel informar um dutycycle de inicio de de final e um periodo para esse incremento ocorrer
~~~c
		ledc_set_fade_time_and_start(LEDC_LOW_SPEED_MODE, 
				LEDC_CHANNEL_0, 
				0, 
				1000, 
				LEDC_FADE_WAIT_DONE);
~~~
    - É necessário fazer a instalação led_fade_func_install