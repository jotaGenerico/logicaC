/*
 * Arquivo: PonteirosFuncoesAritmetica.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

/* protótipo da função zeraArray:
 *     percorre um array e atribui zero a cada uma de suas
 *     posições.
 *     obs: o array será passado como ponteiro e seus
 *          valores poderão ser alterados.
 */
void zerarArray( int *a, int n );

/* protótipo da função zeraArrayErro:
 *     percorre um array e atribui zero a cada uma de suas
 *     posições.
 *     obs: o array será passado como ponteiro e será
 *          de somente leitura (const)!
 */
void zerarArrayErro( const int *a, int n );

/* protótipo da função imprimirArray:
 *     percorre um array e imprime os valores
 *     obs: o array será passado como ponteiro e será
 *          de somente leitura (const)! Na verdade,
 *          a declaração de um parâmetro como array ou
 *          como ponteiro são equivalentes!
 */
void imprimirArray( const int *a, int n );

/* protótipo da função maiorMenor:
 *     percorre um array e encontra o maior e o menor valor
 *     obs: a palavra chave const, no local onde foi utilizada
 *          indica que o array passado é de somente leitura.
 */
void maiorMenor( const int a[], int n, int *max, int *min );

int main( void ) {

    int arrayZerado[10];
    int array[10] = { 2, 3, 4, 1, 0, 2, 6, 4, 15, -5 };
    int *p = array;         // ponteiro para um array
    int quantidade = 10;
    int maior;
    int menor;

    zerarArray( arrayZerado, 10 );
    imprimirArray( arrayZerado, 10 );
    printf( "\n\n" );

    maiorMenor( array, quantidade, &maior, &menor );

    imprimirArray( array, 10 );
    printf( "\nMaior: %d\n", maior );
    printf( "Menor: %d\n\n", menor );

    // **** aritmética de ponteiros ****

    // altera o primeiro elemento do array
    *array = 10;

    // altera o segundo elemento do array
    *(array+1) = 19;

    imprimirArray( array, 10 );

    printf( "\n\n" );
    printf( "p = %p\n", p );
    printf( "array = %p\n\n", array );
    printf( "array[0] = %d\n", array[0] );
    printf( "*p = %d\n\n", *p );
    p++;
    printf( "array[1] = %d\n", array[1] );
    printf( "*p = %d\n\n", *p );
    printf( "array[2] = %d\n", array[2] );
    printf( "*p = %d", *(++p) );

    return 0;

}

void zerarArray( int *a, int n ) {

    for ( int i = 0; i < n; i++ ) {
        a[i] = 0;
    }

}

void zerarArrayErro( const int *a, int n ) {

    for ( int i = 0; i < n; i++ ) {
        // alteração de valor de posição, ERRO de compilação
        //a[i] = 0;
    }

}

void maiorMenor( const int a[], int n, int *max, int *min ) {

    *max = a[0];
    *min = a[0];

    for ( int i = 1; i < n; i++ ) {
        if ( *max < a[i] ) {
            *max = a[i];
        }
        if ( *min > a[i] ) {
            *min = a[i];
        }
    }

}

void imprimirArray( const int *a, int n ) {

    for ( int i = 0; i < n; i++ ) {
        printf( "%d ", a[i] );
    }

}
