/*
 * Arquivo: TratamentoDeErros.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>

/* no cabeçalho errno.h é declarada a variável errno
 * que conterá algum código de erro depois da execução
 * de alguma função que a usa para sinalizar um
 * possível erro.
 *
 * a maioria das funções que modificam errno são as do
 * cabeçalho math.h.
 */

void exemploBasico( void );
void exemploDominio( void );
void exemploIntervalo( void );
void exemploMensagem( void );

int main( void ) {

    exemploBasico();
    exemploDominio();
    exemploIntervalo();
    exemploMensagem();

    return 0;

}

void exemploBasico( void ) {

    float v;

    // zerando a variável errno
    errno = 0;

    // raiz quadrada de um número negativo
    v = sqrt( -9 );

    if ( errno != 0 ) {
        fprintf( stdin, "erro na funcao sqrt, valor negativo\n" );
    } else {
        printf( "v = %.2f", v );
    }

}

void exemploDominio( void ) {

    float v;

    // zerando a variável errno
    errno = 0;

    /* um valor negativo está fora do domínio
     * dos valores permitidos para a função sqrt
     */
    v = sqrt( -9 );

    if ( errno == EDOM ) {
        fprintf( stderr, "erro na funcao sqrt, fora do dominio\n" );
    } else {
        printf( "v = %.2f", v );
    }

}

void exemploIntervalo( void ) {

    double v;

    // zerando a variável errno
    errno = 0;

    /* 1000 é um valor muito grande, ou seja
     * fora do intervalo, permitido para a execução
     * da função exp, que deveria calcular para 1000
     * o valor de e^1000
     */
    v = exp( 1000 );

    if ( errno == ERANGE ) {
        fprintf( stderr, "erro na funcao exp, " );
        fprintf( stderr, "fora do intervalo permitido\n" );
    } else {
        printf( "v = %.2lf", v );
    }

}

void exemploMensagem( void ) {

    double v;
    char mensagem[80];

    // zerando a variável errno
    errno = 0;

    /* qual é o logarítimo base 10 de 0? ou seja
     * qual número deve elevar 10 para resultar em 0?
     */
    v = log10( 0 );

    if ( errno != 0 ) {

        /* a função perror, declarada em stdio.h
         * exibe uma mensagem de erro padronizada
         * para o erro que foi gerado.
         */
        perror( "Erro em log10" );

        /* a função strerror, declarada em string.h
         * recebe um inteiro como parâmetro e gera
         * a mensagem de erro baseada nesse valor.
         * é usada como base dentro da função perror
         * apresentada acima.
         */
        strcpy( mensagem, strerror( errno ) );
        fprintf( stderr, "Mensagem: %s\n", mensagem );

        // ou...
        fprintf( stderr, "Ou: %s\n", strerror( errno ) );

    } else {
        printf( "v = %.2lf", v );
    }


}
