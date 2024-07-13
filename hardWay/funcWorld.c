#include <stdio>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct Person {
	char nome[10]; 
	uint8_t age; 
	uint8_t height; 
}; 


void createPerson(char name[],
	uint8_t age,
	uint8_t height,
	void(*function_pointer)(struct Person)){
		struct Person person; 
		strcpy(person.nome, "Jota"); 
		person.age = 45; 
		person.height = 175; 
		
		(*function_pointer)(person); 
	}


void printPerson(struct Person person) {
	printf("Person: %s %d %d\n",
		person.nome, person.age, person.height); 
}


void printPerson2(struct Person person) {
	printf("Person: %s %d %d\n",
		person.nome, person.age, person.height);
}


void main() {
	
	createPerson("Jota", 45, 175, &printPerson); 
	createPerson("Jota", 45, 175, &printPerson2); 
	
	printf("%c\n", &person); 
	
	return; 
	}
