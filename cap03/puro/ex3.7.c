#include <stdio.h>
#include <stdlib.h>

int main(void){

    int numero;

    printf( "Forneca um numero menor ou igual a zero: " );
    scanf( "%d", &numero );

    if(numero > 0){
        
        printf( "Valor incorreto (positivo)" );

    }else{

        for(numero; numero <= 0; numero++){

            printf("%d ", numero);

        }

    }

    printf("\n");

    return 0;

}