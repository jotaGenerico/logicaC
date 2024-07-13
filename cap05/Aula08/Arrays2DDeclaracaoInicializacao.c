/*
 * Arquivo: Arrays2DDeclaracaoInicializacao.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

// definição da macro M
#define M 5

// definição da macro N
#define N 2

int main( void ) {

    // declaração de um array de dimensões 3x3 de inteiros
    int array1[3][3];

    /* declarando um array de dimensões 2x2 e inicializando
     * com valores 2
     * valor inicializado = { { 2, 2 },
     *                        { 2, 2 } }
     */
    int array2[2][2] = { 2, 2, 2, 2 };

    /* declarando um array de dimensões 2x3 e inicializando
     * com valores
     * valor inicializado = { { 3, 3, 3 },
     *                        { 0, 0, 0 } }
     */
    int array3[2][3] = { 3, 3, 3 };

    /* declarando um array de dimensões 5x2 e inicializando
     * com zeros
     * valor inicializado = { { 0, 0 },
     *                        { 0, 0 },
     *                        { 0, 0 },
     *                        { 0, 0 },
     *                        { 0, 0 } }
     */
    int array4[5][2] = { 0 };

    /* se o inicializador para mais de uma dimensão for usado
     * o tamanho é obrigatório pelo menos para a primeira dimensão
     */
    int array5[3][3] = { { 5, 5, 5 }, { 5, 5, 5 } };
    int array6[][3] = { { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 } };

    /* declaração de um array de inteiros de dimensões MxN
     * M e N são macros que serão expandidas ao serem usadas
     */
    int array7[M][N];


    // cálculo da quantidade de linhas e de colunas usando o operador sizeof
    int linhasArray1 = (int) ( sizeof( array1 ) / sizeof( array1[0] ) );
    int colunasArray1 = (int) ( sizeof( array1[0] ) / sizeof( array1[0][0] ) );

    int linhasArray2 = (int) ( sizeof( array2 ) / sizeof( array2[0] ) );
    int colunasArray2 = (int) ( sizeof( array2[0] ) / sizeof( array2[0][0] ) );

    int linhasArray3 = (int) ( sizeof( array3 ) / sizeof( array3[0] ) );
    int colunasArray3 = (int) ( sizeof( array3[0] ) / sizeof( array3[0][0] ) );

    int linhasArray4 = (int) ( sizeof( array4 ) / sizeof( array4[0] ) );
    int colunasArray4 = (int) ( sizeof( array4[0] ) / sizeof( array4[0][0] ) );

    int linhasArray5 = (int) ( sizeof( array5 ) / sizeof( array5[0] ) );
    int colunasArray5 = (int) ( sizeof( array5[0] ) / sizeof( array5[0][0] ) );

    int linhasArray6 = (int) ( sizeof( array6 ) / sizeof( array6[0] ) );
    int colunasArray6 = (int) ( sizeof( array6[0] ) / sizeof( array6[0][0] ) );


    /* i será usado normalmente para controlar a linha atual
     * e j será usado normalmente para controlar a coluna atual
     * em um array bidimensional.
     */

    for ( int i = 0; i < linhasArray1; i++ ) {
        for ( int j = 0; j < colunasArray1; j++ ) {
            printf( "%d ", array1[i][j] );
        }
        printf( "\n" );
    }
    printf( "\n" );

    for ( int i = 0; i < linhasArray2; i++ ) {
        for ( int j = 0; j < colunasArray2; j++ ) {
            printf( "%d ", array2[i][j] );
        }
        printf( "\n" );
    }
    printf( "\n" );

    for ( int i = 0; i < linhasArray3; i++ ) {
        for ( int j = 0; j < colunasArray3; j++ ) {
            printf( "%d ", array3[i][j] );
        }
        printf( "\n" );
    }
    printf( "\n" );

    for ( int i = 0; i < linhasArray4; i++ ) {
        for ( int j = 0; j < colunasArray4; j++ ) {
            printf( "%d ", array4[i][j] );
        }
        printf( "\n" );
    }
    printf( "\n" );

    for ( int i = 0; i < linhasArray5; i++ ) {
        for ( int j = 0; j < colunasArray5; j++ ) {
            printf( "%d ", array5[i][j] );
        }
        printf( "\n" );
    }
    printf( "\n" );

    for ( int i = 0; i < linhasArray6; i++ ) {
        for ( int j = 0; j < colunasArray6; j++ ) {
            printf( "%d ", array6[i][j] );
        }
        printf( "\n" );
    }
    printf( "\n" );

    for ( int i = 0; i < M; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            printf( "%d ", array7[i][j] );
        }
        printf( "\n" );
    }
    printf( "\n" );

    return 0;

}
