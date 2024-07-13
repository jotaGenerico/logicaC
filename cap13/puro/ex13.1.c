#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *arquivo = fopen("../notas.txt", "r");
    float soma = 0;
    int contagem = 0;
    float nota;    
    float media;

    if (arquivo != NULL){

        while ( !feof( arquivo ) ){

            fscanf(arquivo, "%f", &nota);
            soma += nota;
            contagem++;
        }

        media = soma / contagem;
        printf("Media: %.2f\n", media);
    }
    fclose(arquivo);
    
    return 0;
}