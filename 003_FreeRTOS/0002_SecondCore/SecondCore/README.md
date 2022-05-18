# Segundo Núcleo EP32

- O Esp32 possui 2 núcleos normalmente;
- Em projetos normais o primeiro núcleo rodam as task normais, enquanto o segundo núcleo se coloca para executar parefas em background, como comunicação, em diversos protocolos, incluindo o bluetooth
- Para criar tasks no segundo núcleo do esp32 basta utilizar ao invez da função xTaskCreate, utilizar a função "xTaskCreatePinnedToCore" que possui os mesmos parametro da primeira 
    - É uma função não official presente apenas para microcontroladores Esp32
    - A função "xTaskCreatePinnedToCore" exige um parametro adicional  que é o xCoreID, se 0 utiliza-se o núcleo principal, se coloca-se 1 utiliza-se o segundo núcleo (esse parametro especifica o core de execução, como ao usar xTaskCreate ja cria no core principal, ao utilizar xTaskCreatePinnedToCore utiliza 0 em xCoreID para executar no segundo núcleo)

- Ao utilizar o segundo núcleo o consumo de energia do microcontrolador é aumentado 