# Task Notify 2

- Task Notification também podem ser utilizados para passar informações, este método de passagem de dados não é tão flexivel como as filas (queues);

- O transporte de informações em TaskNotify pode ser feito apenas em variaveis do tipo uint32_t

- A função para escrever dados em um Task Notify é a função xTaskNotify que possui 3 parametros, o primeiro é o Handle da informação, o segundo é o valor que sera armazenado no handle e o terceiro é um bit de configuração (um enum).
    - Cada um dos enuns dão uma caracteristica a como escrever na handle 
        - eNoAction 			
        - eSetBits : Seta o bit selecionado não havendo limpeza dos demais selecionados anteriormente				
        - eIncrement,					
        - eSetValueWithOverwrite: Seta o bit selecionado e limpa os demais 		
        - eSetValueWithoutOverwrite	

- A função para a leitura dos dados possui 4 parametros 
    - O primeiro parametro refere-se a como ocorrerá a limpeza dos dados (se ocorrerá) após a leitura. Deve informar através de um valor em hexa quais os bits deseja-se limpar (ex: 0xffffffff limpa todos os bits por se tratar de TaskNotify se tratar de um inteiro de 32bits). Os dados são limpos na entrada
    - O segundo parametro: mesma coisa que o primeiro parametro entretanto os dados são lidos na saída 
    - O terceiro parametro recebe o ponteiro de um buffer para o valor lido 
    - O quarto parametro refere-se ao tempo de espera para a leitura 


- Task Notify são como pequenas filas "Queues", mutex ou semaforos
