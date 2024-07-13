/* 
 * Arquivo: organizacao-de-codigo/main.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

/* incluindo o cabeçalho que
 * será usado. Note o uso de aspas duplas,
 * indicando que o arquivo geom.h está no mesmo
 * diretório que o arquivo main.c
 */
#include "geom.h"

int main( void ) {

    Ponto p;
    Linha l;
    Retangulo r;
    Elipse e;
    Circulo c;

    p.x = 10;
    p.y = -30;

    l.ini.x = 20;
    l.ini.y = 30;
    l.fim.x = 40;
    l.fim.y = 20;

    r.canto.x = 10;
    r.canto.y = 20;
    r.largura = 20;
    r.altura = 30;

    e.canto.x = 30;
    e.canto.y = 40;
    e.largura = 30;
    e.altura = 10;

    c.centro.x = 50;
    c.centro.y = 80;
    c.raio = 5;


    printf( "Ponto: " );
    imprimirPonto( &p );
    printf( "\n" );

    printf( "Linha: " );
    imprimirLinha( &l );
    printf( "\n" );

    printf( "Retangulo: " );
    imprimirRetangulo( &r );
    printf( "\n" );

    printf( "Elipse: " );
    imprimirElipse( &e );
    printf( "\n" );

    printf( "Circulo: " );
    imprimirCirculo( &c );
    printf( "\n" );

    return 0;

}
