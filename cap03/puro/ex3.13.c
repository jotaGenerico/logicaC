#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n1, n2;
    int m2 = 0, m3 = 0, m4 = 0;

    printf( "N1: " );
    scanf( "%d", &n1 );

    printf( "N2: " );
    scanf( "%d", &n2 );

    if( n1 < n2){

        for(int i = n1; i <= n2; i++){

            if(i % 2 == 0){
                m2++;
                if(i % 4 == 0){
                    m4++;
                }
            }
            if(i % 3 == 0){
                m3++;
            }
        }
            
    }else{

        for(int i = n2; i <= n1; i++){

            if(i % 2 == 0){
                m2++;
                if(i % 4 == 0){
                    m4++;
                }
            }
            if(i % 3 == 0){
                    m3++;
                }
        }


    }

    printf( "Multiplos de 2: %d\n", m2 );
    printf( "Multiplos de 3: %d\n", m3 );
    printf( "Multiplos de 4: %d\n", m4 );

    return 0;

}