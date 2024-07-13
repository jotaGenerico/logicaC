#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define Class struct

Class Person {
    char nome[10];
    uint8_t age;
    uint8_t height;
    void(*show)(Class Person *);
};

void person_print(Class Person *self) {
    printf("nome: %s age: %d height: %d\n",
        self->nome, self->age, self->height);
}

Class Person * newPerson(char name[],
  uint8_t age,
  uint8_t height) {
    Class Person *self =
      (Class Person *) malloc(sizeof(Class Person));
    strcpy(self->nome, "Jota");
    self->age = 45;
    self->height = 175;

    self->show = &person_print;
    return self;
  }

void main() {
    Class Person *person2 = 
      (Class Person *) newPerson("Jota", 45, 175);

    person2->show(person2);

    return;
}
