#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define T 41

int main(void){

    char nome[T];

    printf("Nome: ");
    fgets(nome, T, stdin);
    nome[strlen(nome)-1] = '\0';

    for(int i=0; i < strlen(nome); i++){
        printf("%s\n", nome);
    }
    return 0;
}
