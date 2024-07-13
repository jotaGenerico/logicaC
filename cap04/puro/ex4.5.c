#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void){

    int array[N];
    int quantidade = 0;
    int alvo;
    
    for(int i = 0; i < N; i++){
        printf( "array[%d]", i );
        scanf( "%d", &array[i] );
    }

    printf( "Buscar por: " );
    scanf( "%d", &alvo );

    for(int i = 0; i < N; i++){
        if( array[i] == alvo){
            quantidade++;
        }
    }
    if(quantidade > 0){
        if(quantidade == 1){
            printf( "O array contem %d ocorrencia do valor %d.\n", quantidade, alvo );
        }
        else{
            printf( "O array contem %d ocorrencias do valor %d.\n", quantidade, alvo );
        }
    }
    else{
        printf( "O array nao contem o valor %d.\n", alvo );
    }

    return 0;
}