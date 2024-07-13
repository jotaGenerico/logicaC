#include <stdio.h>
#include <stdlib.h>

int main(void){

    int num1;
    int num2;
    int num3;

    printf( "N1: " );
    scanf( "%d", &num1 );

    printf( "N2: " );
    scanf( "%d", &num2 );

    printf( "N3: " );
    scanf( "%d", &num3 );

    if( num1 >= num2 && num1 >= num3){

        if( num2 >= num3){

            printf( " %d >= %d >= %d \n", num1, num2, num3 );

        }else{

            printf( "%d >= %d >= %d\n", num1, num3, num2 );

        }

    }else if( num2 >= num1 && num2 >= num3){

        if(num1 >= num3){

            printf( "%d >= %d >= %d\n", num2, num1, num3 );

        }else{

            printf( "%d >= %d >= %d\n", num2, num3, num1 );

        }

    }else{

        if(num1 >= num2){

            printf( "%d >= %d >= %d\n", num3, num1, num2 );

        }else{

            printf( "%d >= %d >= %d\n", num3, num2, num1 );
        }
    }

    return 0;

}