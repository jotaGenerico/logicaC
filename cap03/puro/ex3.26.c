#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n;
    int maiorN;
    int menorN;
    int primeiro = 1;

    do{

        printf( "Entre com um valor: " );
        scanf( "%d", &n );

        if(n < 0){
            if( primeiro == 1){
                maiorN = 0;
                menorN = 0;
            }

            break;
        }
        
        if(primeiro == 1){
            maiorN = n;
            menorN = n;
            primeiro = 0;            
        }
        
        else{
            maiorN = (n > maiorN)?n:maiorN;
            menorN = (n < menorN)?n:menorN;
        }        
        
    }while(n >= 0);

    printf( "Menor numero: %d\n", menorN );
    printf( "Maior numero: %d\n", maiorN );

    return 0;

}