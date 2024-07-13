#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void){

    int array1[N];
    int array2[N];
    int arraySoma[N];

    printf( "Forneca os valores do primeiro array: \n" );

    for(int i = 0; i < N; i++){
        printf( "array1[%d]: ", i );
        scanf( "%d", &array1[i] );
    }

    printf( "Forneca os valores do segundo array: \n" );

    for(int i = 0; i < N; i++){
        printf( "array2[%d]: ",i );
        scanf( "%d", &array2[i] );
    }

    for(int i = 0; i < N; i++){
        arraySoma[i] = array1[i] + array2[i];
        printf( "arraySoma[%d] = %d\n",i ,arraySoma[i] );
    }

    return 0;

}