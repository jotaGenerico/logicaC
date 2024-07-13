#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void){

    float array[N];
    float somatorio = 0;
    float produtorio = 1;

    for(int i = 0; i < N; i++){
        printf( "array[%d]: ",i );
        scanf( "%f", &array[i] );
    }
    for(int i = 0; i < N; i++){
        somatorio+= array[i];
        produtorio*=array[i];
    }
    printf( "Somatorio: %.2f\n", somatorio );
    printf( "Produtorio: %.2f\n", produtorio );

    return 0;

}