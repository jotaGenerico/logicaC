#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n;
    int fatorial = 1;

    printf( "Numero: " );
    scanf( "%d", &n );

    if(n < 0){
        printf( "Nao ha fatorial de numero negativo.\n " );

    }else{
        for(int i = n; i > 0; i--){
            fatorial *= i;

        }

    printf( "%d! = %d\n", n, fatorial );

    }
    
    return 0;
}