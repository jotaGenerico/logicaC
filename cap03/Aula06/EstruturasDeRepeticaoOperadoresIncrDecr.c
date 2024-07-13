/*
 * Arquivo: EstruturasDeRepeticaoOperadoresIncrDecr.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

int main( void ) {

    /* o funcionamento do operador unário de decremento (--)
     * é análogo ao operador unário de incremento (++).
     */

    int i = 0;

    printf( "%d\n", i );   // imprime 0

    i++;  // incremento pós-fixado
    printf( "%d\n", i );   // imprime 1

    ++i;  // incremento pré-fixado
    printf( "%d\n", i );   // imprime 2

    /* incremento pós-fixado em uma expressão
     * usa o valor, depois incrementa.
     */
    printf( "%d\n", i++ ); // imprime 2
    printf( "%d\n", i );   // imprime 3

    /* incremento pré-fixado em uma expressão
     * incrementa depois usa o valor.
     */
    printf( "%d\n", ++i ); // imprime 4
    printf( "%d", i );     // imprime 4

    return 0;

}
