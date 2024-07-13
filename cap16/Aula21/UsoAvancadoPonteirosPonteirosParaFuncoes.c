/*
 * Arquivo: UsoAvancadoPonteirosPonteirosParaFuncoes.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenar( int *valores, int n );

/* A função ordenarUsandoFuncao tem como terceiro parâmetro
 * um ponteiro para uma função, chamado pFuncao (indicado
 * por (*pFuncao), sendo que esse ponteiro é capaz de apontar
 * para funções que retornam inteiros e que têm dois parâmetros
 * inteiros.
 */
void ordenarUsandoFuncao( int *valores, int n,
                          int (*pFuncao)( int n1, int n2 ) );
void embaralhar( int *valores, int n );

void imprimir( int *p, int n );
int sortear( int inicio, int fim );

int crescente( int n1, int n2 );
int decrescente( int n1, int n2 );
void imprimirMensagem( void );

int main( void ) {

    int v[10] = { 3, 5, 1, 4, 3, 9, 4, 2, -1, -3 };
    int t = 10;

    /* declaração e inicialização de um ponteiro para
     * uma função que não retorna nada e não possui
     * parâmetros.
     */
    void (*pFV)( void ) = imprimirMensagem;

    /* declaração de um ponteiro para uma função que
     * retorna um inteiro e recebe dois inteiros
     * como parâmetro
     */
    int (*pFDec)( int, int );
    pFDec = decrescente;


    srand( time( NULL ) );


    imprimirMensagem();
    printf( "(invocacao de imprimirMensagem)\n" );
    pFV();
    printf( "(invocacao indireta via pFV)\n\n" );

    printf( "Embaralhando...\n" );
    embaralhar( v, t );
    imprimir( v, t );

    printf( "Ordenado:\n" );
    ordenar( v, t );
    imprimir( v, t );


    printf( "\n\nEmbaralhando...\n" );
    embaralhar( v, t );
    imprimir( v, t );

    printf( "Ordenado crescente usando 'int crescente(int, int)':\n" );
    ordenarUsandoFuncao( v, t, crescente );
    imprimir( v, t );


    printf( "\n\nEmbaralhando...\n" );
    embaralhar( v, t );
    imprimir( v, t );

    printf( "Ordenado decrescente usando pFDec:\n" );
    ordenarUsandoFuncao( v, t, pFDec );
    imprimir( v, t );

    return 0;

}

void ordenar( int *valores, int n ) {

    int t;

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n-1; j++ ) {
            if ( valores[j] > valores[j+1] ) {
                t = valores[j];
                valores[j] = valores[j+1];
                valores[j+1] = t;
            }
        }
    }

}

void ordenarUsandoFuncao( int *valores, int n,
                          int (*pFuncao)( int n1, int n2 ) ) {

    int t;
    int c;

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n-1; j++ ) {

            // invocando a função passada como parâmetro
            c = pFuncao( valores[j], valores[j+1] );

            if ( c > 0 ) {
                t = valores[j];
                valores[j] = valores[j+1];
                valores[j+1] = t;
            }

        }
    }

}

void embaralhar( int *valores, int n ) {

    int p;
    int t;

    for ( int i = 0; i < n; i++ ) {
        p = sortear( 0, n-1 );
        t = valores[i];
        valores[i] = valores[p];
        valores[p] = t;
    }

}

void imprimir( int *p, int n ) {

    for ( int i = 0; i < n; i++ ) {
        printf( "%d ", p[i] );
    }
    printf( "\n" );

}

int sortear( int inicio, int fim ) {
    return inicio + ( rand() % ( fim - inicio + 1 ) );
}

int crescente( int n1, int n2 ) {
    return n1 - n2;
}

int decrescente( int n1, int n2 ) {
    return n2 - n1;
}

void imprimirMensagem( void ) {
    printf( "Comecando..." );
}
