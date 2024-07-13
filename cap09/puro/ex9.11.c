#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarOcorrencias(const char *str, char c);

#define T 41

int main(void){

    char string[T];
    char alvo;
    int ocorrencias;
    int fim = 1;

    printf("Caractere: ");
    alvo = getchar();
    getchar();

    do{

        printf("Frase: ");
        fgets(string, T, stdin);
        string[strlen(string)-1] = '\0';

        if(strcmp(string, "fim") == 0){
            fim = 0;
        }
        else{
            ocorrencias = contarOcorrencias(string, alvo);

            printf("\"%s\" tem %d ocorrencia(s) do caractere \'%c\'\n", string, ocorrencias, alvo);
        }

    }while(fim);
    
    return 0;
}

int contarOcorrencias(const char *str, char c){
    int contador = 0;

    for(int i=0; i < strlen(str); i++){
        if(c == str[i]){
            contador++;
        }
    }
    return contador;
}
