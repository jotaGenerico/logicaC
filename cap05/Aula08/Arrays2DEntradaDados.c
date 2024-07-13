/*
 * Arquivo: Arrays2DEntradaDados.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

int main( void ) {

    // declaração de um array de inteiros de dimensões 2x3
    int array[2][3];

    // cálculo da quantidade de linhas e de colunas usando o operador sizeof
    int linhas = (int) ( sizeof( array ) / sizeof( array[0] ) );
    int colunas = (int) ( sizeof( array[0] ) / sizeof( array[0][0] ) );

    // lista os dados do array (não foi inicializado!)
    for ( int i = 0; i < linhas; i++ ) {
        for ( int j = 0; j < colunas; j++ ) {
            printf( "%d ", array[i][j] );
        }
        printf( "\n" );
    }
    printf( "\n" );

    // inserção dos dados
    for ( int i = 0; i < linhas; i++ ) {
        for ( int j = 0; j < colunas; j++ ) {
            printf( "Entre com o valor da posicao [%d][%d]: ", i, j );
            scanf( "%d", &array[i][j] );
        }
    }

    printf( "Dados inseridos:\n" );
    for ( int i = 0; i < linhas; i++ ) {
        for ( int j = 0; j < colunas; j++ ) {
            printf( "%d ", array[i][j] );
        }
        printf( "\n" );
    }
    printf( "\n" );

    return 0;

}
