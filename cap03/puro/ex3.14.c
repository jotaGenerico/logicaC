#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n1, n2;
    int soma = 0;

    printf( "N1: " );
    scanf( "%d", &n1 );

    printf( "N2: " );
    scanf( "%d", &n2 );

    if( n1 < n2){
        for( int i = n1; i <= n2; i++){
            soma += i;
        }

    printf( "Somatorio entre %d e %d: %d\n",n1 , n2, soma );

    }else{
        for( int i = n2; i <= n1; i++){
            soma += i;
        }

    printf( "Somatorio entre %d e %d: %d\n",n2 , n1, soma );

    }

    return 0;

}