#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 41

int main(void){

    char sentenca[T];
    char primeiro;
    char ultimo;
    int quantidade;

    printf("Sentenca: ");
    fgets(sentenca, T, stdin);
    sentenca[strlen(sentenca)-1] = '\0';

    primeiro = sentenca[0];
    ultimo = sentenca[strlen(sentenca)-1];
    quantidade = strlen(sentenca);

    printf("Primeiro caractere: %c\n"
           "Ultimo caractere: %c\n"
           "Numero de caracteres: %d\n", primeiro, ultimo, quantidade);

    return 0;
}