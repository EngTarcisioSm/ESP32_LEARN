#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person_Struct {
	char firstName[20];
	char lastName[20];
	int age;
	void (*vDoWork)(char *pcDataRetrieved);
} Person_t;

void vUpdatePerson(Person_t *person, char *pvDataRetrieved) {
	strcpy(person->firstName, "Bob");
	strcpy(person->lastName, "Fisher");
	person->age = 35;
}

void connectAndGetInfo(char *pcUrl, void (*vDoWork)(char *pcDataRetrieved)) {
	/* connect to wireless */

	/* connect to endpoint */

	/* allocate memory */
	char *pcDataRetrieved = (char *)malloc(1024);

	/* efetua a requisição dos dados: getRequest(&pcDataRetrieved) */

	/* aloca os dados dentro da estrutura Person_t */
	vDoWork(pcDataRetrieved);
	/* Limpa a memoria e os recursos */
	free((void *) pcDataRetrieved);
}

void vDoWorkForPerson(char *pvDataRetrieved) {
	Person_t person;

	vUpdatePerson(&person, pvDataRetrieved);
	printf("person: %s %s is %d years old\n", person.firstName, person.lastName, person.age);


}

void app_main(void)
{
	connectAndGetInfo("http://getperson.com", vDoWorkForPerson);
}
