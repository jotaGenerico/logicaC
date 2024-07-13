#include <stdio.h>
#include <stdlib.h>

#define T 5

int main(void){

    FILE *arquivoBase = fopen("../numeros.txt", "r");
    int absolutos[T];
    int absoluto;
    char nomeArquivo[15];
    FILE *arquivoSaida;
    char asteriscos[15];

    if(arquivoBase != NULL){

        while(!feof(arquivoBase)){

            for(int i=0; i < T; i++){

                fscanf(arquivoBase, "%d", &absoluto);
                absolutos[i] = 10 - absoluto;
            }
        }
    }

    fclose(arquivoBase);

    for(int i=0; i < T; i++){
        
        sprintf(nomeArquivo, "../tri%d.txt", i+1);
        arquivoSaida = fopen(nomeArquivo, "w");
        
        for(int j=0; j < absolutos[i]; j++){
            for(int k=0; k < j+1; k++){
                fputs("*", arquivoSaida);
            }
            if(j < absolutos[i] - 1){
                fputs("\n",arquivoSaida);
            }
        }

        fclose(arquivoSaida);
    }
    
    for(int i=0; i < T; i++){
        
        sprintf(nomeArquivo, "../tri%d.txt", i+1);
        arquivoBase = fopen(nomeArquivo, "r");

        while(!feof(arquivoBase)){

            fgets(asteriscos, 15, arquivoBase);
            printf("%s", asteriscos);
        }

        printf("\n");
        fclose(arquivoBase);
    }

    return 0;
}