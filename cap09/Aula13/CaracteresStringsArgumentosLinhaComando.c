/*
 * Arquivo: CaracteresStringsArgumentosLinhaComando.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <string.h>
#include <ctype.h>
#include <math.h>


bool ehInteiro( const char *string );

/* A função main aceita 3 assinaturas no padrão da linguagem C.
 * O primeiro já é conhecido: int main( void ).
 * O segundo e o terceiro são análogos. Uma de suas formas é usada
 * abaixo. A outra é int main( int argc, char **argv )
 *
 * Através das formas 2 e 3 permitidas, podemos processar
 * argumentos passados via linha de comando ao se executar o
 * programa.
 *
 * argc (argument count) é um inteiro que contém a quantidade de
 * argumentos que foram enviados para a execução. argv (argument
 * values) é um array de strings que contém o valor de cada argumento.
 */
int main( int argc, char *argv[] ) {

    int n1;
    int n2;

    if ( argc > 1 ) {

        if ( strcmp( argv[1], "/?" ) == 0 ) {
            printf( "Programa desenvolvido por David Buzatto." );
        } else if ( strcmp( argv[1], "/calc" ) == 0 ) {

            if ( argc == 5 ) {

                if ( ehInteiro( argv[2] ) ) {
                    n1 = atoi( argv[2] );
                } else {
                    printf( "Voce precisa fornecer numeros inteiros!" );
                    return 1;
                }

                if ( ehInteiro( argv[4] ) ) {
                    n2 = atoi( argv[4] );
                } else {
                    printf( "Voce precisa fornecer numeros inteiros!" );
                    return 1;
                }

                if ( strcmp( argv[3], "+" ) == 0 ) {
                    printf( "%d + %d = %d", n1, n2, n1 + n2 ) ;
                } else if ( strcmp( argv[3], "-" ) == 0 ) {
                    printf( "%d - %d = %d", n1, n2, n1 - n2 ) ;
                } else if ( strcmp( argv[3], "x" ) == 0 ) {
                    printf( "%d x %d = %d", n1, n2, n1 * n2 ) ;
                } else if ( strcmp( argv[3], "/" ) == 0 ) {
                    printf( "%d / %d = %d", n1, n2, n1 / n2 ) ;
                } else if ( strcmp( argv[3], "pow" ) == 0 ) {
                    printf( "%d pow %d = %d", n1, n2, (int) pow( n1, n2 ) ) ;
                } else {
                    printf( "Operador invalido!" );
                    return 1;
                }

            }

        }

    }

    return 0;

}

bool ehInteiro( const char *string ) {

    for ( int i = 0; i < strlen( string ); i++ ) {
        if ( !isdigit( string[i] ) ) {
            return false;
        }
    }

    return true;

}
