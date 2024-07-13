/*
 * Arquivo: UsoAvancadoPonteirosPonteirosParaPonteiros.c
 * Autor: Prof. Dr. David Buzatto
 * 
 * Discussão sobre:
 * - https://stackoverflow.com/q/5580761/469201
 */

#include <stdio.h>
#include <stdlib.h>

void naoAltera( int *a, int *b );
void alterar( int **a, int *b );

int main( void ) {
    
    /* ponteiros para ponteiros, ou ponteiros duplos,
     * são usados para alterar, indiretamente, o
     * valor de um ponteiro.
     */
    int n1 = 10;
    int n2 = 12;
    int n3 = 14;

    int *p1 = &n1;
    int *p2 = &n2;
    int *p3 = &n3;

    int **pp = &p1;

    printf( "p1: %p\n", p1 );
    printf( "p2: %p\n", p2 );
    printf( "p3: %p\n\n", p3 );

    p1 = p2;
    printf( "p1 = p2;\n" );
    printf( "p1: %p\n", p1 );
    printf( "p2: %p\n", p2 );
    printf( "p3: %p\n\n", p3 );

    naoAltera( p1, p3 );
    printf( "naoAltera( p1, p3 );\n" );
    printf( "p1: %p\n", p1 );
    printf( "p2: %p\n", p2 );
    printf( "p3: %p\n\n", p3 );

    alterar( pp, p3 );
    printf( "alterar( pp, p3 );\n" );
    printf( "p1: %p\n", p1 );
    printf( "p2: %p\n", p2 );
    printf( "p3: %p", p3 );

    return 0;

}


void naoAltera( int *a, int *b ) {
    a = b;
    *a = 20;
}

void alterar( int **a, int *b ) {
    *a = b;
}
