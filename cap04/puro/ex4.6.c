#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void){

    int array[N];
    int indices[N];
    int ocorrencia = 0;
    int alvo;

    for(int i = 0; i < N; i++){
        printf( "array[%d]: ", i );
        scanf( "%d", &array[i] );
    }

    printf( "Buscar por: " );
    scanf( "%d", &alvo );

    for( int i = 0; i < N; i++){
        if(array[i] == alvo){
            indices[ocorrencia] = i;
            ocorrencia++;
        }
    }

    if(ocorrencia > 0){
        printf( "O valor %d foi encontrado no", alvo );

            if (ocorrencia == 1) {
                printf(" indice %d ", indices[0]);
            }
            else if(ocorrencia == 2){
                printf( "s indices %d e %d ", indices[0], indices[1] );
            }
            else{
                printf( "s indices " );
                for(int i = 0; i < ocorrencia; i++){
                    if(i == ocorrencia -1){
                        printf( "e %d ",indices[i] );
                    }
                    else {
                        printf("%d", indices[i]);
                        if (i != ocorrencia - 2){
                            printf(", ");
                        }
                        else {
                            printf(" ");
                        }
                    }
                }            
            }

    printf( "do array.\n" );    
    }
    else{
        printf( "O array nao contem o valor %d.\n", alvo );
    }
    
    return 0;
}