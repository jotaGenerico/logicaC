/* 
 * Arquivo: CaracteresStringsFuncoes.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   

/* string.h é o cabeçalho necessário para utilizar as
 * funções de manipulação de strings na linguagem C.
 */

int main( void ) {

    char string1[30] = "david";
    char string2[30] = "fernanda";
    char string3[30] = "buzatto";
    char string4[30];
    int comparacao;

    /* size_t strlen( const char *str )
     * Retorna o tamanho da string (quantidade de
     * caracteres armazenados).
     */
    printf( "A string \"%s\" possui %d caracteres.\n",
           string1, strlen( string1 ) );

    /* int strcmp( const char *str1, const char *str2 )
     * Compara str1 com str2 e retorna:
     *     um valor negativo, caso str1 venha antes de str2;
     *     zero, caso str1 seja igual a str2;
     *     um valor positivo, caso str1 venha após str2.
     */
    comparacao = strcmp( string1, string2 );
    if ( comparacao < 0 ) {
        printf( "%s vem antes de %s!\n", string1, string2 );
    } else if ( comparacao > 0 ) {
        printf( "%s vem antes de %s!\n", string2, string1 );
    } else {
        printf( "%s e %s tem o mesmo conteudo!\n", string1, string2 );
    }

    /* char *strcat( char *destino, const char *fonte );
     * Concatena em destino o conteúdo de fonte.
     */
    strcat( string1, " " );
    strcat( string1, string3 );
    printf( "%s\n", string1 );

    /* char *strcpy( char *destino, const char *fonte );
     * Copia em destino o conteúdo de fonte.
     */
    strcpy( string4, "aurora" );
    printf( "%s\n", string4 );

    return 0;

}
