/*
 * Arquivo: PonteirosDeclaracaoInicializacao.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

int main( void ) {

    int numeroInt = 10;
    float numeroFloat = 15.5;

    // declaração de um ponteiro para inteiro
    int *pInt;

    /* declaração de um ponteiro para float
     * e inicialização. O operador & é chamado
     * operador de endereço
     */
    float *pFloat = &numeroFloat;

    // atribuindo um endereço ao ponteiro pInt
    pInt = &numeroInt;

    /* utilização de operador de indireção (*) para
     * acessar o valor de uma variável de forma indireta.
     */
    printf( "numeroInt: %d\n", numeroInt );
    printf( "numeroFloat: %.2f\n", numeroFloat );
    printf( "*pInt: %d\n", *pInt );
    printf( "*pFloat: %.2f\n\n", *pFloat );

    /* impressão de endereços. especificador de
     * formato %p
     */
    printf( "&numeroInt: %p\n", &numeroInt );
    printf( "&numeroFloat: %p\n", &numeroFloat );
    printf( "pInt: %p\n", pInt );
    printf( "pFloat: %p\n\n\n", pFloat );


    numeroInt = 4;

    /* utilização de operador de indireção (*) para
     * alterar o valor de uma variável de forma indireta.
     */
    *pFloat = 21.7;

    printf( "numeroInt: %d\n", numeroInt );
    printf( "numeroFloat: %.2f\n", numeroFloat );
    printf( "*pInt: %d\n", *pInt );
    printf( "*pFloat: %.2f\n\n", *pFloat );

    printf( "&numeroInt: %p\n", &numeroInt );
    printf( "&numeroFloat: %p\n", &numeroFloat );
    printf( "pInt: %p\n", pInt );
    printf( "pFloat: %p\n\n\n", pFloat );

    return 0;

}
