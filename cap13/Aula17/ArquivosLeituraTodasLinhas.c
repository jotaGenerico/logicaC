/* 
 * Arquivo: ArquivosLeituraTodasLinhas.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

int main( void ) {

    FILE *arquivo;
    char dadosLinha[80];

    arquivo = fopen( "arquivoDados.txt", "r" );

    if ( arquivo != NULL ) {
        // lê o arquivo, linha por linha, e imprime na tela
        while ( !feof( arquivo ) ) {
            fgets( dadosLinha, 80, arquivo );
            printf( "%s", dadosLinha );
        }
    }

    fclose( arquivo );

    return 0;

}
