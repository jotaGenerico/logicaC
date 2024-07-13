/*
 * Arquivo: ArraysUnidimensionaisEntradaDados.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

int main( void ) {

    // declaração de um array de inteiros de 5 posições
    int array[5];

    // cálculo do tamanho usando o operador sizeof
    int t = (int) ( sizeof( array ) / sizeof( array[0] ) );


    // lista os dados do array (não foi inicializado!)
    for ( int i = 0; i < t; i++ ) {
        printf( "%d ", array[i] );
    }
    printf( "\n" );

    // inserção dos dados
    for ( int i = 0; i < t; i++ ) {
        printf( "Entre com o valor da posicao %d: ", i );
        scanf( "%d", &array[i] );
    }

    printf( "Dados inseridos: " );
    for ( int i = 0; i < t; i++ ) {
        printf( "%d ", array[i] );
    }
    printf( "\n" );


    return 0;

}
