/*
 * Arquivo: CaracteresStringsConceitosES.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* função imprimeCaixa recebe um ponteiro para
 * char e um inteiro como parâmetro.
 * As mesmas regras vistas para ponteiros se aplicam.
 */
void imprimeCaixa( const char *str, int largura );

void removePuloLinha( char *str );

int main( void ) {

    /* Em C, não existe um tipo específico para Strings,
     * mas sim arrays de char marcados no final com um
     * caractere nulo. Sendo assim as Strings em C são
     * também chamadas de "null-terminated Strings"
     */

    /* array de chars inicializado com um literal
     * de String. Usará 13 posições para armazenar
     * os caracteres e uma posição para armazenar
     * o caractere nulo ('\0').
     */
    char nomeCompleto[30] = "David Buzatto";

    /* perceba a necessidade de inserir o caractere
     * nulo como como último caractere.
     */
    char outraForma[10] = { 'o', 'l', 'a', '\0' };

    /* um ponteiro de char apontando para a String
     * criada usando um literal.
     */
    char *nomeComPonteiro = "Joao da Silva";

    // 29 caracteres no máximo
    char string1[30];
    char string2[30];
    char string3[30];

    // erro de compilação.
    // só se pode usar o literal na inicialização
    //string1 = "abc";

    // cinco strings de 29 caracteres
    char conjuntoStrings[5][30];

    /* imprimindo as strings usando o especificador
     * de formato %s
     */
    printf( "%s\n%s\n",
           nomeCompleto,
           nomeComPonteiro );

    /* uma outra forma de imprimir uma string é
     * usando a função puts. Ele já pula uma linha.
     */
    puts( outraForma );

    /* uma string pode ser "quebrada" para fins de
     * visibilidade.
     */
    printf( "Essa eh uma string que ficou feia no \
           codigo, pois eh muito comprida e \
           dificulta a leitura, entendeu?\n" );

    // assim é melhor!
    printf( "Essa eh uma string que ficou feia no "
           "codigo, pois eh muito comprida e "
           "dificulta a leitura, entendeu?\n" );

    // a leitura pode ser feita de algumas formas

    /* scanf: termina quando encontra algum
     * caractere de espaço, ficando o restante no buffer
     */
    printf( "Entre com a string 1: " );
    scanf( "%s", string1 ); // não use &, string1 é um ponteiro
    getchar(); // descarta o caractere de nova linha do buffer

    /* gets: faz a leitura completa, mas deixa o
     * pulo de linha no buffer e pode gerar overflow
     */
    printf( "Entre com a string 2: " );
    gets( string2 );
    getchar(); // descarta o caractere de nova linha do buffer

    /* fgets: consome todo o buffer, inserindo o
     * pulo de linha antes do caractere nulo e evita
     * overflow. Vamos usar essa função!
     */
    printf( "Entre com a string 3: " );

    /* char *fgets ( char *str, int num, FILE *stream )
     *        char *str: ponteiro para a string que armazenará
     *                   a leitura.
     *          int num: limite de caracteres suportados
     *                   (incluindo o '\0').
     *     FILE *stream: um ponteiro para arquivo,
     *                   usaremos stdin.
     * Retorna o próprio ponteiro passado caso tenha sucesso
     * ou o ponteiro NULL caso haja algum erro na leitura.
     */
    fgets( string3, 30, stdin );
    string3[strlen(string3)-1] = '\0'; // remove pulo de linha

    printf( "string1: %s\n", string1 );
    printf( "string2: %s\n", string2 );
    printf( "string3: %s\n", string3 );

    for ( int i = 0; i < 5; i++ ) {
        printf( "string %d: ", i );
        fgets( conjuntoStrings[i], 30, stdin );
    }

    for ( int i = 0; i < 5; i++ ) {
        removePuloLinha( conjuntoStrings[i] );
        imprimeCaixa( conjuntoStrings[i], 30 );
    }


    return 0;

}

void imprimeCaixa( const char *str, int largura ) {

    int c = largura - 3 - strlen( str );

    printf( "+" );
    for ( int i = 0; i < largura-2; i++ ) {
        printf( "-" );
    }
    printf( "+\n" );

    printf( "| %s", str );
    for ( int i = 0; i < c; i++ ) {
        printf( " " );
    }
    printf( "|\n" );

    printf( "+" );
    for ( int i = 0; i < largura-2; i++ ) {
        printf( "-" );
    }
    printf( "+\n" );

}

void removePuloLinha( char *str ) {

    int i = 0;
    while ( str[i] != '\0' ) {
        i++;
    }
    str[i-1] = '\0';

}
