#include <stdio.h>
#include <stdlib.h>

int main(void){

    int numeros[5];

    printf("Digite 5 numeros positivos:\n");
    for(int i = 0; i < 5; i++){
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
        
        if(numeros[i] <= 0){
            printf("Forneca apenas numeros positivos.\n");
            return 0;
        }
    }

    

    int maximo = 0;
    for(int i = 0; i < 5; i++){
        if(numeros[i] > maximo){
            maximo = numeros[i];
        }
    }

    int scala = maximo;
    printf("\n");
    
    for(int linha = maximo; linha > 0; linha--){
        printf("%04d  ", scala--);
        for(int coluna = 0; coluna < 5; coluna++){
            if (numeros[coluna] >= linha) {                
                printf("*");
            } else {                
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}
