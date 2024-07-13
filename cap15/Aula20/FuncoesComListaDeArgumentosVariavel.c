/*
 * Arquivo: FuncoesComListaDeArgumentosVariavel.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* stdarg.h é o cabeçalho necessário para a declaração
 * e definição de funções com lista de argumentos variável.
 */

/* declaração da função maximo que possui um
 * parâmetro inteiro (quantidade) e um parâmetro
 * variável (...).
 *
 * o padrão da linguagem C exige que exista pelo menos
 * um parâmetro normal antes do parâmetro variável,
 * além do que deve haver apenas um o parâmetro variável
 * e ele deve estar obrigatoriamente no final da lista
 * de argumentos.
 */
int maximo( int quantidade, ... );

/* declaração da função minimo que possui um
 * parâmetro inteiro (quantidade) e um parâmetro
 * variável (...).
 */
int minimo( int quantidade, ... );

int main( void ) {

    int maior = maximo( 10, 4, 5, 9, 7, 8, 4, 5, 3, 2, 1 );
    int menor = minimo( 10, 4, 5, 9, 7, 8, 4, 5, 3, 2, 1 );

    printf( "Maior: %d\n", maior );
    printf( "Menor: %d", menor );

    return 0;

}

int maximo( int quantidade, ... ) {

    /* variável "argumentos" do tipo va_list
     * que vai ser usada para obter os argumentos
     * passados através do parâmetro variável.
     */
    va_list argumentos;

    int atual;
    int maior;

    // inicia a captura dos argumentos
    va_start( argumentos, quantidade );

    // obtém o primeiro item, um inteiro
    maior = va_arg( argumentos, int );

    for ( int i = 1; i < quantidade; i++ ) {

        // obtém o próximo item, um inteiro
        atual = va_arg( argumentos, int );

        if ( atual > maior ) {
            maior = atual;
        }

    }

    // termina a captura dos argumentos
    va_end( argumentos );

    return maior;

}

int minimo( int quantidade, ... ) {

    va_list argumentos;
    int atual;
    int menor;

    va_start( argumentos, quantidade );
    menor = va_arg( argumentos, int );

    for ( int i = 1; i < quantidade; i++ ) {

        atual = va_arg( argumentos, int );

        if ( atual < menor ) {
            menor = atual;
        }

    }

    va_end( argumentos );

    return menor;

}
