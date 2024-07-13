#include <stdio.h>
#include <stdlib.h>

int main(void){

    int quantidadeLados;
    float tamanhoLados;
    
    printf( "Entre com a quantidade de lados: " );
    scanf( "%d", &quantidadeLados );

    printf( "Entre com a medida do lado: " );
    scanf( "%f", &tamanhoLados );

    if(quantidadeLados >= 3 && quantidadeLados <= 5){        
        if(quantidadeLados == 3){
            
            printf( "TRIANGULO de perimetro %.2f\n", 3 * tamanhoLados );

        }else if(quantidadeLados == 4){
            
            printf( "QUADRADO de area %.2f\n", tamanhoLados * tamanhoLados );

        }else{

            printf( "PENTAGONO\n" );
        }

    }else{

        printf( "Poligono nao identificado\n" );

    }

    return 0;

}