#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverter(char *destino, const char *base, int tamanho);

#define T 41

int main(void){

    int tamanho;
    char invertida[T];
    char original[T];

    printf("String: ");
    fgets(original, T, stdin);
    original[strlen(original)-1] = '\0';


    tamanho = strlen(original);

    inverter(invertida, original, tamanho );

    printf("Invertida: %s\n", invertida);
    return 0;
}

void inverter(char *destino, const char *base, int tamanho){
    if(tamanho <= 0){
        *destino = '\0';
    } else {
        *destino = base[tamanho - 1];
        inverter(destino + 1, base, tamanho - 1);
    }
}