#include <stdio.h>
#include <stdlib.h>

int main(void){

    int numero;

    printf( "Forneca um numero menor ou igual a zero: " );
    scanf( "%d", &numero );

    if (numero > 0){

        printf( "Valor incorreto (positivo)" );

    }else{

        for (int i = 0; i >= numero; i--){

            printf( "%d ", i );

        }

    }

    printf("\n");

    return 0;

}