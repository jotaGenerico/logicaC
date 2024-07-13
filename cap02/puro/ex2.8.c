#include <stdio.h>
#include <stdlib.h>

int main(void){

    float num1;
    float num2;
    float num3;

    float primeiro;
    float segundo;

    printf( "N1: " );
    scanf( "%f", &num1 );

    printf( "N2: " );
    scanf( "%f", &num2 );

    printf( "N3: " );
    scanf( "%f", &num3 );

    if(num1 > num2 && num1 > num3){

        if(num2 > num3){

            primeiro = num1;
            segundo = num2;

        }else{

            primeiro = num1;
            segundo = num3;
        }

    }else if(num2 > num1 && num2 > num3){

        if(num1 > num3){

            primeiro = num2;
            segundo = num1;

        }else{

            primeiro = num2;
            segundo = num3;

        }

    }else{

        if(num1 > num2){

            primeiro = num3;
            segundo = num1;

        }else{

            primeiro = num3;
            segundo = num2;

        }

    }

    printf( "A soma dos dois numeros maiores fornecidos e %.2f\n", primeiro + segundo );

    return 0;

}