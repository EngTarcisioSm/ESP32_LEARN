# Componentização de código

- Por muitas vezes se deseja reutilizar determinado código (biblioteca), seja pessoal ou baixada da internet;

- IDF possui vinculado a ele a componentização de código;

- Esse processo se resume a criar uma pasta dentro do diretorio geral do projeto e essa parta abrigar os arquivos C e H da biblioteca, para isso é necessário seguir os passos abaixo, passos utilizados para esp32/eclipse
    - Com o projeto aberto no qual será criado o novo componente clicar em:
        File > New > Other...
    - Na janela aberta selecionar 
        Espressif > Espressif IDF Component
    - Clicar em Finish 
    - Será aberto uma nova janela 
        Em "Component Name" colocar o nome do novo componente 
    
    - Será criado uma pasta com a seguinte estrutura 
    ~~~
        components
            |--- nome_modulo
                    |---include
                        nome_modulo.h
                    nome_modulo.c   
                    CMakeList.txt
    ~~~