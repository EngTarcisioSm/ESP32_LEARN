# Ponteiro de Função

- Recurso muito utilizado na IDF

- Ao alocar memoria com malloc() sempre será retornado um ponteiro do tipo vazio

- Ao liberar o buffer com a função free() deve-se sinalizar o ponteiro como void

- Para passar como atributo para uma função uma outra função deve-se obedecer a seguinte estrutura 
    - tipo_funcão (*nome_ponteiro função)(atributos que a função utilizará com seus tipos)
    - Exemplo
~~~c
    void connectAndGetInfo(char *pcUrl, void (*vDoWork)(char *pcDataRetrieved)) {
        /*codigo*/
        vDoWork(pcData);
    }
~~~
    - Dentro da função connectAndGetInfo(), qualquer função passada no segundo parametro que tenha como atributo um ponteiro do tipo char pode ser utilizada dentro da função connectAndGetInfo() com o nome vDoWork()
    - Para passar a função como parametro basta passar o nome da função, desde que a função atenda aos prérequisitos de tipo da função e tipo dos atributos 
- Exemplo passando como parametro
~~~c
    connectAndGetInfo("http://getperson.com", vDoWorkForPerson);
~~~

- Ponteiros de funções se comportam quase como variáveis 

- É possivel fazer o mesmo processo para structs obedecendo a mesma logica, fincando disponivel um ponteiro de função dentro da struct que deve ser preenchido por uma função 
- Exemplo 
~~~c
typedef struct Person_Struct {
	char firstName[20];
	char lastName[20];
	int age;
	void (*vDoWork)(char *pcDataRetrieved);
} Person_t;
~~~
    - Observando que é necessário passar a função que será armazenada, como se fosse uma variavel, ou seja, apenas seu nome 
- Exemplos de uso 
~~~c
    person.vDoWork = vDoWorkForPerson;      //sendo a propria estrutura
    //ou
    person->vDoWork = vDoWorkForPerson;     //sendo a estrutura passada como ponteiro 
~~~
    - lembrando que vDoWorkForPerson() deve atender aos pré requisitos da função, em seu tipo de retorno, quantidade e tipo de atributos 

- Funções também podem ser devolvidas como um retorno de função


