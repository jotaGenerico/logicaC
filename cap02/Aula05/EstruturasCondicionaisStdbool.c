/*
 * Arquivo: EstruturasCondicionaisStdbool.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* stdbool.h é o cabeçalho que contém o tipo bool
 * e as palavras chave true e false.
 *
 * o tipo bool não é um tipo nativo da linguagem C
 * como int ou char. sendo assim, é necessário
 * incluir o cabeçalho stdbool caso queira utilizá-lo.
 */

int main( void ) {

    // variável do tipo bool
    bool maiorDeIdade;
    int idade;

    printf( "Entre com sua idade: " );
    scanf( "%d", &idade );

    if ( idade < 18 ) {
        // false é o valor que indica falso
        maiorDeIdade = false;
    } else {
        // true é o valor que indica verdadeiro
        maiorDeIdade = true;
    }

    // o if anterior poderia ser substituído por
    maiorDeIdade = idade >= 18;

    // ou
    maiorDeIdade = !( idade < 18 );

    /* maiorDeIdade armazena verdadeiro ou falso, sendo assim
     * pode ser usado diretamente no lugar do teste lógico.
     */
    if ( maiorDeIdade ) {
        printf( "Voce eh maior de idade!" );
    } else {
        printf( "Voce nao eh maior de idade!" );
    }

    return 0;

}
