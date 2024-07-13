#include <stdio.h>
#include <stdlib.h>

int main(void){

    int h1, h2, m1, m2;
    int hv, hn;
    int mv, mn;

    printf( "Idade Homem 1: " );
    scanf( "%d", &h1 );

    printf( "Idade Homem 2: " );
    scanf( "%d", &h2 );

    printf( "Idade Mulher 1: " );
    scanf( "%d", &m1 );

    printf( "Idade Mulher 2: " );
    scanf( "%d", &m2 );

    if(h1 > h2){

        hv = h1;
        hn = h2;

    }else{

        hv = h2;
        hn = h1;

    }

        if(m1 > m2){

        mv = m1;
        mn = m2;

    }else{

        mv = m2;
        mn = m1;
        
    }

    printf( "Idade homem mais velho + idade mulher mais nova: %d\n", hv + mn );
    printf( "Idade homem mais novo * idade mulher mais velha: %d\n", hn * mv );

    return 0;

}
