#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void){

    int array[N];
    int alvo;

    for(int i = 0; i < N; i++){
        printf( "array[%d]: ", i );
        scanf( "%d", &array[i] );
    }
    printf( "Busca por: " );
    scanf( "%d", &alvo );

    for(int i = 0; i < N; i++){
        if(alvo == array[i]){
            printf( "Indice %d: ACHEI\n", i );
        }
        else{
            printf( "Indice %d: NAO ACHEI\n", i );
        }
    }

    return 0;

}