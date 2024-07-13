/* 
 * Arquivo: organizacao-de-codigo/geom.c
 * Autor: Prof. Dr. David Buzatto
 */

/* cada arquivo de cabeçalho, usualmente,
 * terá um arquivo de implementação/definição
 * (extensão .c).
 */
#include <stdio.h>
#include <stdlib.h>
#include "geom.h"
/* na linha acima: incluindo o cabeçalho que
 * será implementado. Note o uso de aspas duplas,
 * indicando que o arquivo geom.h está no mesmo
 * diretório que o arquivo geom.c
 */

/* no arquivo de implementação, as funções
 * declaradas no cabelho e demais entidades
 * de programação será utilizadas.
 */

void imprimirPonto( Ponto *ponto ) {
    printf( "(%+03d, %+03d)", ponto->x, ponto->y );
}

void imprimirLinha( Linha *linha ) {
    imprimirPonto( &linha->ini );
    printf( " ====== " );
    imprimirPonto( &linha->fim );
}

void imprimirRetangulo( Retangulo *retangulo ) {
    printf( "C: " );
    imprimirPonto( &retangulo->canto );
    printf( " L: %d, A: %d", retangulo->largura, retangulo->altura );
}

void imprimirElipse( Elipse *elipse ) {
    printf( "C: " );
    imprimirPonto( &elipse->canto );
    printf( " L: %d, A: %d", elipse->largura, elipse->altura );
}

void imprimirCirculo( Circulo *circulo ) {
    printf( "C: " );
    imprimirPonto( &circulo->centro);
    printf( " R: %d", circulo->raio );
}
