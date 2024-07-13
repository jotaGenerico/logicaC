#include <stdio.h>
#include <stdlib.h>

int main(void){

    int numero;

    printf( "Forneca um numero maior ou igual a 0: " );
    scanf( "%d", &numero);

    if(numero < 0){

        printf( "Valor incorreto (negativo)" );

    }else{

        for (numero; numero >= 0; numero--){

            printf( "%d ", numero );
        }

    }

    printf("\n");

    return 0;

}