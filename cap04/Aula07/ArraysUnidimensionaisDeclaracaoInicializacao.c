/*
 * Arquivo: ArraysUnidimensionaisDeclaracaoInicializacao.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

// definição da macro N
#define N 10

int main( void ) {

    // declaração de um array de inteiros de 5 posições
    int array1[5];

    // declarando um array e inicializando com valores 2
    // valor inicializado = { 2, 2, 2, 2, 2 }
    int array2[5] = { 2, 2, 2, 2, 2 };

    // declarando um array e inicializando com valores 3
    // valor inicializado = { 3, 3, 0, 0, 0 }
    int array3[5] = { 3, 3 };

    // declarando um array e inicializando com zeros
    // valor inicializado = { 0, 0, 0, 0, 0 }
    int array4[5] = { 0 };

    // se o inicializador for usado, o tamanho pode ser omitido
    // valor inicializado = { 5, 5, 5 }
    int array5[] = { 5, 5, 5 };

    // declaração de um array de inteiros de N posições
    // N é uma macro que será expandida ao ser usada
    int array6[N];

    /* array6 = { 0 };
     * ou
     * array6[] = { 0 };
     *
     * inválido, pois o inicializador só pode ser usado na declaração
     */

    // cálculo do tamanho usando o operador sizeof
    int tamanhoArray1 = (int) ( sizeof( array1 ) / sizeof( array1[0] ) );
    int tamanhoArray2 = (int) ( sizeof( array2 ) / sizeof( array2[0] ) );
    int tamanhoArray3 = (int) ( sizeof( array3 ) / sizeof( array3[0] ) );
    int tamanhoArray4 = (int) ( sizeof( array4 ) / sizeof( array4[0] ) );
    int tamanhoArray5 = (int) ( sizeof( array5 ) / sizeof( array5[0] ) );

    for ( int i = 0; i < tamanhoArray1; i++ ) {
        printf( "%d ", array1[i] );
    }
    printf( "\n" );

    for ( int i = 0; i < tamanhoArray2; i++ ) {
        printf( "%d ", array2[i] );
    }
    printf( "\n" );

    for ( int i = 0; i < tamanhoArray3; i++ ) {
        printf( "%d ", array3[i] );
    }
    printf( "\n" );

    for ( int i = 0; i < tamanhoArray4; i++ ) {
        printf( "%d ", array4[i] );
    }
    printf( "\n" );

    for ( int i = 0; i < tamanhoArray5; i++ ) {
        printf( "%d ", array5[i] );
    }
    printf( "\n" );

    for ( int i = 0; i < N; i++ ) {
        printf( "%d ", array6[i] );
    }
    printf( "\n" );


    return 0;

}
