#include <stdio.h>
#include <stdlib.h>

int main(void){

    int idade;
    int atual = 1;
    int menos21 = 0 ;
    int mais50 = 0 ;

    do{

        printf( "Idade da pessoa %02d: ", atual++ );
        scanf( "%d", &idade );

        if(idade >= 0){
            if(idade <= 21){
                menos21++;
            
            }else if(idade >=50){
                mais50++;

            }
        }
    }while(idade > 0);

    printf( "Total de pessoas menores de 21 anos: %d\n", menos21 );
    printf( "Total de pessoas com mais de 50 anos: %d\n", mais50 );

     return 0;

}