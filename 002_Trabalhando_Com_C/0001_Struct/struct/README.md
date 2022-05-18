# Struct

- Em C usamos a palavra reservada struct para criar uma estrutura 

- Estruturas em C são representações de algo do mundo real descritas atraves de algumas variaveis 

- Estrutura de uma struct 
~~~c
    struct NomeStruct {
        //variaveis
    };
~~~
- Exemplo
~~~c
    struct Person {
        char firstName[20];
        char lastName[20];
        uint8_t age;
    }
~~~
- Atribuição de uma struct já desenvolvida 
~~~c
    struct NomeStruct nome;
~~~
- Como acessar dados de uma struct 
~~~c
    nome.nome_variavel
~~~

- É possivel definir uma struct de uma forma mais clean utilizando a palavra reservada typdef e dando um nome para esse tipo 

- Exemplo
~~~c
    typedef struct Nome_struct {
        //variaveis
    }Nome;
~~~

- Desta forma torna-se não necessário a utilização da palabra "struct" na hora da atribuição de uma struct 

- É possivel utilizar structs como parametros de funções, entretanto ao utilizar ponteiros em estruturas seu acesso interno a função se modifica um pouco. Ao querer acessar um ente da struct o acesso deixa de ser feito atraves do "."(ponto) e passa a ser atraves do operador arrow "->"