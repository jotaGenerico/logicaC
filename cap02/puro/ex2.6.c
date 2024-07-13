#include <stdio.h>
#include <stdlib.h>

int main(void){

    float num1;
    
    printf( "Entre com um valor: " );
    scanf( "%f", &num1 );

    if(num1 > 20 ){

        printf( "A metade de %.2f e %.2f\n", num1, num1 / 2 );

    }else{

        printf( "O triplo de %.2f e %.2f\n", num1, num1 * 3 );

    }
    
    return 0;

}