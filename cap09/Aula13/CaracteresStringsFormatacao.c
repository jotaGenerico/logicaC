/*
 * Arquivo: CaracteresStringsFormatacao.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

int main( void ) {

    char string[30];

    int dia = 25;
    int mes = 2;
    int ano = 1985;

    /* int sprintf( char *buffer, const char *formato, ... );
     *
     * A função sprintf é definida no cabeçalho stdio.h e
     * é usada para realizar o mesmo trabalho que a função
     * printf, só que, ao invés de enviar a String formatada
     * para a saída, ela armazena o resultado em uma String.
     *
     * Todas as regras de formatação aplicadas no printf
     * são aplicadas na sprintf também.
     */
    sprintf( string, "%02d/%02d/%04d", dia, mes, ano );
    printf( "%s", string );

    return 0;

}
