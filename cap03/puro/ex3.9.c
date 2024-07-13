#include <stdio.h>
#include <stdlib.h>

int main(void){

    int numero;

    printf( "Tabuada do numero: " );
    scanf( "%d", &numero );

    for (int i = 0; i <= 10; i++){
        
        printf( "%d x %d = %d\n", numero, i, numero * i);

    }

    return 0;

}
