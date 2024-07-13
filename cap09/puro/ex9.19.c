#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void substring(char *recorte, const char *origem, int inicio, int fim);

#define T 41

int main(void){

    int i, f;
    char original[T];
    char recorte[T];
    char validacao[T];

    printf("String: ");
    fgets(original, T, stdin);
    original[strlen(original)-1] = '\0';

    printf("Inicio: ");
    scanf("%d", &i);

    printf("Fim: ");
    scanf("%d", &f);

    substring(recorte, original, i, f);

    printf("Recorte: %s", recorte);

    return 0;
}

void substring(char *recorte, const char *origem, int inicio, int fim){
    int index = 0;
    int tamanho = strlen(origem) - 1;

    if( fim < tamanho && inicio < fim){
        for(int j=inicio; j < fim; j++){
        recorte[index++] = origem[j];
        }
    }
    else{
        strcpy(recorte, origem);
    }
}
