#include <stdio.h>
#include <stdlib.h>

int main(void){

    int nt;
    int fibonacci;
    int t1 = 0;
    int t2 = 1;

    printf( "Termo desejado: " );
    scanf( "%d", &nt );

    for(int i = 0; i <= nt; i++){
        fibonacci = t1 + t2;
        t1 = t2;
        t2 = fibonacci;

    }

    printf( "Fibonacci de %d e %d\n", nt, t1 );

    return 0;

}