/*
 * Arquivo: Enumeracoes.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* os valores enumerados das enumerações são definidos
 * normalmente usando somente letras maiúsculas.
 */

/*
 * enumeração anônima
 * valores enumerados: VERMELHO, VERDE e AZUL
 */
enum {
    VERMELHO,
    VERDE,
    AZUL
} e1, e2, en;

/*
 * enumeração chamada tamanho
 * valores enumerados: P, M, G, GG, EG
 */
enum tamanho {
    P,
    M,
    G,
    GG,
    EG
};

/*
 * definição de tipo (Naipe) usando
 * uma enumeração chamada Naipe.
 * atenção: essa é a forma que usaremos.
 */
typedef enum Naipe {
    COPAS,
    OUROS,
    PAUS,
    ESPADAS
} Naipe;

/*
 * definição de tipo (Carta) usando
 * estrutura e enumeração.
 */
typedef struct Carta {
    int valor;
    Naipe naipe;
} Carta;

/*
 * definição de tipo (Baralho) usando
 * um array de estrutura.
 */
typedef struct Baralho {
    Carta cartas[52];
} Baralho;

Baralho novoBaralho( void );
void imprimirCarta( Carta *c );
void imprimirBaralho( Baralho *b );

int main( void ) {

    Baralho b = novoBaralho();

    imprimirBaralho( &b );

    return 0;

}

Baralho novoBaralho( void ) {

    Baralho b;
    Naipe naipes[4] = { COPAS, OUROS, PAUS, ESPADAS };
    int valores[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    int c = 0;

    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 13; j++ ) {
            b.cartas[c].naipe = naipes[i];
            b.cartas[c].valor = valores[j];
            c++;
        }
    }

    return b;

}

void imprimirCarta( Carta *c ) {

    char valor[3];
    char naipe;

    switch ( c->valor ) {
        case 1:
            strcpy( valor, "A" );
            break;
        case 2:
            strcpy( valor, "2" );
            break;
        case 3:
            strcpy( valor, "3" );
            break;
        case 4:
            strcpy( valor, "4" );
            break;
        case 5:
            strcpy( valor, "5" );
            break;
        case 6:
            strcpy( valor, "6" );
            break;
        case 7:
            strcpy( valor, "7" );
            break;
        case 8:
            strcpy( valor, "8" );
            break;
        case 9:
            strcpy( valor, "9" );
            break;
        case 10:
            strcpy( valor, "10" );
            break;
        case 11:
            strcpy( valor, "J" );
            break;
        case 12:
            strcpy( valor, "Q" );
            break;
        case 13:
            strcpy( valor, "K" );
            break;
    }

    switch ( c->naipe ) {
        case COPAS:
            naipe = 'C';
            break;
        case OUROS:
            naipe = 'O';
            break;
        case PAUS:
            naipe = 'P';
            break;
        case ESPADAS:
            naipe = 'E';
            break;
    }

    printf( "%s(%c)", valor, naipe );

}

void imprimirBaralho( Baralho *b ) {

    for ( int i = 1; i <= 52; i++ ) {
        imprimirCarta( &(b->cartas[i-1]) );
        printf( " " );
        if ( i % 13 == 0 ) {
            printf( "\n" );
        }
    }

}
