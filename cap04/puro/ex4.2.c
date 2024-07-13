#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void){

    int array[N];
    int arrayMultiplos[N];
    int multiplo;

    for(int i = 0; i < N; i++){
        printf( "array[%d]: ", i );
        scanf( "%d", &array[i] );
    }
    printf( "Multiplicar por: " );
    scanf( "%d", &multiplo );

    for(int i = 0; i < N; i++){
        arrayMultiplos[i] = multiplo * array[i];
    }

    for(int i = 0; i < N; i++){
        printf( "arrayMult[%d] = %d\n", i, arrayMultiplos[i] );
    }

    return 0;

}