#include <stdio.h>
#include <stdlib.h>

int main(void){

    int numero1;
    int numero2;

    printf( "Entre com um numero: " );
    scanf( "%d", &numero1 );

    printf( "Entre com outro numero: " );
    scanf( "%d", &numero2 );

    if(numero1 <= numero2){

        printf( "Ordem crescente: %d <= %d\n", numero1, numero2  );

    }else{

        printf( "Ordem crescente: %d <= %d\n", numero2, numero1 );

    }

    return 0;

}
