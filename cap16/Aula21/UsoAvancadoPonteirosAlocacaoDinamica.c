/*
 * Arquivo: UsoAvancadoPonteirosAlocacaoDinamica.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

void imprimir( int *p, int n );
void configurar( int *p, int n, int valor );

int main( void ) {

    int t = 10;

    /* void* malloc( size_t tamanhoTotal )
     *
     * A função malloc é utilizada para alocar dinamicamente
     * uma quantidade de memória em bytes.
     *
     * Retorna um ponteiro para o início da região alocada
     * caso haja espaço livre ou NULL caso não seja possível
     * alocar espaço. O ponteiro retornado é um ponteiro do
     * tipo void*, chamado de ponteiro genérico. Para a
     * atribuição desse retorno a um ponteiro, há a necessidade
     * de se realizar um cast (coerção explícita) para o tipo
     * de ponteiro necessário.
     */
    int *p1 = (int*) malloc( t * sizeof(int) );

    /* void* calloc( size_t quantidade, size_t tamanhoItem )
     *
     * A função calloc é utilizada para alocar dinamicamente
     * uma quantidade de memória em bytes e recebe dois
     * parâmetros: o primeiro é a quantidade de elementos
     * a serem alocados e o segundo é o tamanho de cada
     * elemento. A função calloc também zera a região alocada.
     *
     * Retorna um ponteiro para o início da região alocada
     * caso haja espaço livre ou NULL caso não seja possível
     * alocar espaço.
     */
    int *p2 = (int*) calloc( t, sizeof(int) );

    if ( p1 != NULL && p2 != NULL ) {

        imprimir( p1, t );
        imprimir( p2, t );

        configurar( p1, t, 1 );
        configurar( p2, t, 2 );

        imprimir( p1, t );
        imprimir( p2, t );

    }

    /* liberando o espaço alocado
     * SEMPRE LIBERE O ESPAÇO ALOCADO DINAMICAMENTE!!!
     */
    free( p1 );
    free( p2 );

    /* cuidado! a partir daqui, a região apontada por p1 e p2
     * não é mais válida!!!
     *
     * cuidado! não invoque free mais de uma vez para o mesmo
     * ponteiro!
     *
     * cuidado! se alguma operação de aritmética de ponteiros
     * for feita, a invocação de free não terá o comportamento
     * esperado.
     */

    return 0;

}

void imprimir( int *p, int n ) {

    for ( int i = 0; i < n; i++ ) {
        printf( "%d ", p[i] );
    }
    printf( "\n" );

}

void configurar( int *p, int n, int valor ) {

    for ( int i = 0; i < n; i++ ) {
        p[i] = valor;
    }

}
