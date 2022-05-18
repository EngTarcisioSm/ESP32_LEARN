# DAC

- ESP32 possui um dac de 8bits 

- Ao total o esp possui 2 DAC alocados no pino 25(channel 1) e 26(channel 2) respectivamente 

- A resolução do Dac é de aproximadamente 12mV

- O processo de utilização é muito simples 

- O primeiro passo é incluir a biblioteca "driver/dac.h"

- A partir da inclusão da biblioteca basta apenas configurar qual dos canais estará sendo utilizado atravez da função 
    ~~~c
        dac_output_enable(parametro); //recebe o canal  atravez de um define da propria lib, DAC_CHANNEL_1 ou DAC_CHANNEL_2
    ~~~

- O proximo passo é escrever a tensão desejada de 0 a 255 por se tratar de um dac de 8bits com resolução de 12mV. Esse processo é feito atraves da função abaixo que possui dois parametros 
    - canal de escrita do dac
    - valor de 0 a 255

    ~~~c
        dac_output_voltage(parametro1, parametro2);
    ~~~

- Observações:
    - O valor 0 (zero) respectivamente não é 0V
    - O valor 255 não é 3.3V
    - Deve ser feito um calculo para analisar o valor de intervalo útil