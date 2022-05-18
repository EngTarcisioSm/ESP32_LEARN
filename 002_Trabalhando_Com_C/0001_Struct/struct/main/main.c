#include <stdio.h>
#include <string.h>

struct Person {
	char firstName[20];
	char lastName[20];
	uint8_t age;
};

typedef struct Person2_struct {
	char firstName[20];
	char lastName[20];
	uint8_t age;
} Person2;

void vAttPerson(Person2 *person) {
	strcpy(person->firstName, "Sofia");
	strcpy(person->lastName, "Melo");
	person->age = 0;
}

void app_main(void) {
	struct Person person;

	strcpy(person.firstName, "Tarcisio");
	strcpy(person.lastName, "Melo");
	person.age = 33;

	printf("person: %s %s is %d years old\n", person.firstName, person.lastName,
			person.age);

	Person2 person2;

	strcpy(person2.firstName, "Bryan");
	strcpy(person2.lastName, "Melo");
	person2.age = 6;

	printf("person: %s %s is %d years old\n", person2.firstName, person2.lastName,
				person2.age);

	Person2 person3;
	vAttPerson(&person3);

	printf("person: %s %s is %d years old\n", person3.firstName, person3.lastName,
					person3.age);

}
