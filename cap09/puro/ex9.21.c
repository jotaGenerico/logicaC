#include <stdio.h>
#include <string.h>

#define COLUNAS 80

void imprimirCentralizado(const char *str);

int main(void){

    char string[COLUNAS];

    printf("String: ");
    fgets(string, COLUNAS, stdin);
    string[strcspn(string, "\n")] = '\0';

    imprimirCentralizado(string);

    return 0;
}

void imprimirCentralizado(const char *str){
    int tamanho = strlen(str);
    int inicio = (COLUNAS - tamanho) / 2;

    for(int i = 0; i < inicio; i++){
        putchar(' ');
    }

    printf("%s\n", str);
}
