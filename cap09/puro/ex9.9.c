#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverter(char *destino, const char *origem);

#define T 41

int main(void){
    
    char string[T];
    char reversa[T];

    printf("String: ");
    fgets(string, T, stdin);
    string[strlen(string)-1] = '\0';

    inverter(reversa, string);

    return 0;
}

void inverter(char *destino, const char *origem){

    int total = strlen(origem);
    int negativo = total -1;

    for(int i=0; i < total; i++){
           destino[i] = origem[negativo--];
    }
    destino[total] = '\0';

    printf("Invertida: %s\n", destino);
}