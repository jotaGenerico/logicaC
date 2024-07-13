/* 
 * Arquivo: ArquivosEscrita.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimeConteudo( FILE *file );

int main( void ) {

    FILE *arquivo;
    char dados[80];
    int inteiro;
    float decimal;

    arquivo = fopen( "arquivoEscrita.txt", "w" );

    if ( arquivo != NULL ) {

        printf( "Entre um uma frase: " );
        fgets( dados, 80, stdin );
        dados[strlen(dados)-1] = '\0';

        printf( "Escrevendo no arquivo...\n" );

        // escreve no arquivo usando fprintf
        fprintf( arquivo, "%s", dados );

        // escreve no arquivo um caractere
        fputc( '\n', arquivo );

        // escreve no arquivo uma string
        fputs( "mais uma linha para o arquivo!\n", arquivo );


        printf( "Entre com um inteiro: " );
        scanf( "%d", &inteiro );

        printf( "Entre com um decimal: " );
        scanf( "%f", &decimal );

        // escreve no arquivo usando fprintf
        fprintf( arquivo, "inteiro escrito: %d\n", inteiro );
        fprintf( arquivo, "decimal escrito: %f", decimal );


    } else {
        printf( "O arquivo nao pode ser aberto!" );
    }

    fclose( arquivo );

    // imprimindo dados
    imprimeConteudo( fopen( "arquivoEscrita.txt", "r" ) );


    return 0;

}

void imprimeConteudo( FILE *a ) {

    char dadosLinha[80];

    if ( a != NULL ) {
        while ( !feof( a ) ) {
            fgets( dadosLinha, 80, a );
            printf( "%s", dadosLinha );
        }
    }

    fclose( a );

}
