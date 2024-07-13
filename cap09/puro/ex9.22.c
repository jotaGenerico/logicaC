#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void imprimirDireita(const char *str);

#define COLUNAS 80

int main(void){

    char string[COLUNAS];

    printf("String: ");
    fgets(string, COLUNAS, stdin);
    string[strcspn(string, "\n")] = '\0';

    imprimirDireita(string);
    
    return 0;
}

void imprimirDireita(const char *str){

    int tamanho = strlen(str);
    int inicio = COLUNAS - tamanho -1;

    for(int i=0; i < inicio; i++){
        printf(" ");
    }

    printf("%s\n", str);
}
