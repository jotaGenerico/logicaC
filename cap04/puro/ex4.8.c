#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void){

    int array[N];
    int pares[N];
    int impares[N];
    int par = 0;
    int impar = 0;

    for(int i = 0; i < N; i++){
        printf( "array[%d]: ", i );
        scanf( "%d", &array[i] );
    }

    for(int i = 0; i < N; i++){
        if(array[i] % 2 == 0){
            pares[par] = array[i];
            par++;
        }
        else{
            impares[impar] = array[i];
            impar++;
        }
    }

    printf( "Numeros pares:" ); 
    if( par == 0){
        printf( " nao ha.\n" );
    }
    else{            
        for(int i = 0; i < par; i++){
            printf( " %d",pares[i] );
        }
        printf( ".\n" );
    }

    printf( "Numeros impares:" );
    if(impar == 0){
        printf( " nao ha.\n" );
    }
    else{
        for(int i = 0; i < impar; i++){
            printf( " %d", impares[i] );
        }
        printf( ".\n" );
    }

    return 0;

}