/* 
 * Arquivo: CaracteresStringsManipulacaoCaracteres.c
 * Autor: Prof. Dr. David Buzatto
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    

/* ctype.h é o cabeçalho necessário para utilizar as
 * funções de manipulação de caracteres na linguagem C.
 */

int main( void ) {

    /* int isalpha( int c )
     * Retorna um valor verdadeiro se c for uma letra ou 0 (falso)
     * em caso contrário.
     */
    printf ( "%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "De acordo com isalpha: ",
            isalpha('A') ? "A eh uma " : "A nao eh uma ", "letra",
            isalpha('b') ? "b eh uma " : "b nao eh uma ", "letra",
            isalpha('&') ? "& eh uma " : "& nao eh uma ", "letra",
            isalpha('4') ? "4 eh uma " : "4 nao eh uma ", "letra" );

    /* int isalnum( int c )
     * Retorna um valor verdadeiro se c for um dígito ou uma
     * letra ou 0 (falso) em caso contrário.
     */
    printf( "%s\n%s%s\n%s%s\n%s%s\n\n", "De acordo com isalnum: ",
            isalnum('A') ? "A eh um " : "A nao eh um ",
           "digito ou uma letra",
            isalnum('8') ? "8 eh um " : "8 nao eh um ",
           "digito ou uma letra",
            isalnum('#') ? "# eh um " : "# nao eh um ",
           "digito ou uma letra" );

    /* int isdigit( int c )
     * Retorna um valor verdadeiro se c for um dígito ou 0 (falso)
     * em caso contrário
     */
    printf( "%s\n%s%s\n%s%s\n\n", "De acordo com isdigit: ",
           isdigit('8') ? "8 eh um " : "8 nao eh um ", "digito",
           isdigit('#') ? "# eh um " : "# nao eh um ", "digito" );

    /* int isxdigit( int c )
     * Retorna um valor verdadeiro se c for um caractere de dígito
     * hexadecimal ou 0 (falso) em caso contrário.
     */
    printf( "%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n",
           "De acordo com isxdigit:",
            isxdigit('F') ? "F eh um " : "F nao eh um ",
           "digito hexadecimal",
            isxdigit('J') ? "J eh um " : "J nao eh um ",
           "digito hexadecimal",
            isxdigit('7') ? "7 eh um " : "7 nao eh um ",
           "digito hexadecimal",
            isxdigit('$') ? "$ eh um " : "$ nao eh um ",
           "digito hexadecimal",
            isxdigit('f') ? "f eh um " : "f nao eh um ",
           "digito hexadecimal" );

    /* int islower( int c )
     * Retorna um valor verdadeiro se c for uma letra minúscula ou 0
     * (falso) em caso contrário.
     */
    printf( "%s\n%s%s%s\n%s%s%s\n\n", "De acordo com islower:",
            "a", islower('a') ? " eh um " : " nao eh um ",
            "caractere em caixa baixa (minusculo)",
            "A", islower('A') ? " eh um " : " nao eh um ",
            "caractere em caixa baixa (minusculo)" );

    /* int isupper( int c )
     * Retorna um valor verdadeiro se c for uma letra maiúscula ou 0
     * (falso) em caso contrário.
     */
    printf( "%s\n%s%s%s\n%s%s%s\n\n", "De acordo com isupper:",
            "a", isupper('a') ? " eh um " : " nao eh um ",
            "caractere em caixa alta (maiusculo)",
            "A", isupper('A') ? " eh um " : " nao eh um ",
            "caractere em caixa alta (maiusculo)" );

    /* int tolower( int c )
     * Se c for uma letra maiúscula, tolower retorna c como uma
     * letra minúscula. Caso contrário, tolower retorna o argumento
     * inalterado.
     */
    printf( "%s\n%s%c\n%s%c\n%s%c\n\n", "Usando tolower:",
            "tolower('a'): ", tolower('a'),
            "tolower('A'): ", tolower('A'),
            "tolower('#'): ", tolower('#') );

    /* int toupper( int c )
     * Se c for uma letra minúscula, toupper retorna c como uma
     * letra maiúscula. Caso contrário, toupper retorna o argumento
     * inalterado.
     */
    printf( "%s\n%s%c\n%s%c\n%s%c\n\n", "Usando toupper:",
            "toupper('a'): ", toupper('a'),
            "toupper('A'): ", toupper('A'),
            "toupper('#'): ", toupper('#') );

    /* int isspace( int c )
     * Retorna um valor verdadeiro se c for um caractere de espaço
     * em branco: nova linha ('\n'), espaço (' '), avanço de folha
     * ('\f'), retorno de carro ('\r'), tabulação horizontal ('\t') ou
     * tabulação vertical ('\v') ou 0 (falso) em caso contrário.
     */
    printf( "%s\n%s%s%s\n%s%s%s\n%s%s\n\n", "De acordo com isspace:",
            "'Nova linha'", isspace('\n') ? " eh um " : " nao eh um ",
            "caractere de espaco em branco",
            "'Tab. hor.'", isspace('\t') ? " eh um " : " nao eh um ",
            "caractere de espaco em branco",
            isspace('%') ? "% eh um " : "% nao eh um ",
            "caractere de espaco em branco" );

    /* int isblank( int c )
     * Retorna um valor verdadeiro se c for um caractere de espaço:
     * espaço (' ') ou tabulação horizontal ('\t') ou 0 (falso)
     * em caso contrário.
     */
    printf( "%s\n%s%s%s\n%s%s%s\n%s%s\n\n", "De acordo com isblank:",
            "'Nova linha'", isblank('\n') ? " eh um " : " nao eh um ",
            "caractere em branco",
            "'Tab. hor.'", isblank('\t') ? " eh um " : " nao eh um ",
            "caractere em branco",
            isblank('%') ? "% eh um " : "% nao eh um ",
            "caractere em branco" );


    /* int iscntrl( int c )
     * Retorna um valor verdadeiro se c for um caractere de controle
     * ou 0 (falso) caso contrário.
     */
    printf( "%s\n%s%s%s\n%s%s\n\n", "De acordo com iscntrl:",
            "'Nova linha'", iscntrl('\n') ? " eh um " : " nao eh um ",
            "caractere de controle ",
            iscntrl('$') ? "$ eh um " : "$ nao eh um ",
            "caractere de controle" );

    /* int ispunct( int c )
     * Retorna um valor verdadeiro se c for um caractere imprimível
     * diferente de espaço, um dígito ou uma letra ou 0 (falso) caso
     * contrário.
     */
    printf( "%s\n%s%s\n%s%s\n%s%s\n\n", "De acordo com ispunct:",
            ispunct(';') ? "; eh um " : "; nao eh um ",
            "caractere de pontuacao",
            ispunct('Y') ? "Y eh um " : "Y nao eh um ",
            "caractere de pontuacao",
            ispunct('#') ? "# eh um " : "# nao eh um ",
            "caractere de pontuacao" );

    /* int isprint( int c )
     * Retorna um valor verdadeiro se c for um caractere imprimível
     * incluindo espaço (' ') ou 0 (falso) em caso contrário.
     */
    printf ( "%s\n%s%s\n%s%s%s\n\n", "De acordo com isprint:",
            isprint('$') ? "$ eh um " : "$ nao eh um ",
            "caractere imprimivel",
            "'Alerta'", isprint('\a') ? " eh um " : " nao eh um ",
            "caractere imprimivel" );

    /* int isgraph( int c ) Retorna um valor verdadeiro se c for um
     * caractere imprimível diferente de espaço (' ') ou 0 (falso)
     * em caso contrário.
     */
    printf( "%s\n%s%s\n%s%s%s\n", "De acordo com isgraph:",
            isgraph('Q') ? "Q eh um " : "Q nao eh um ",
            "caractere imprimivel diferente de um espaco",
            "Espaco", isgraph(' ') ? " eh um " : " nao eh um ",
            "caractere imprimivel diferente de um espaco" );

    return 0;

}
