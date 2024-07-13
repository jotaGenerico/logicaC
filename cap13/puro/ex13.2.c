#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *arquivo = fopen("../barras.txt", "r");
    int comprimento;

    if(arquivo != NULL){

        while(!feof(arquivo)){
            fscanf(arquivo, "%d", &comprimento);

            for(int i = 0; i < comprimento; i++){
                printf("*");
            }
            printf(" (%d)\n", comprimento);
        }
    }

    fclose(arquivo);
    
    return 0;
}