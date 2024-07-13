#include "Placar.h"
#include "raylib.h"

void desenharPlacar( Placar *placar ) {

    int xc1 = (int) ( GetScreenWidth() * 0.25 );
    int xc2 = (int) ( GetScreenWidth() * 0.75 );
    int y = 40;
    int tamFonte = 60;

    const char *p1 = TextFormat( "%d", placar->jogador1->pontuacao );
    const char *p2 = TextFormat( "%d", placar->jogador2->pontuacao );

    int w1 = MeasureText( p1, tamFonte );
    int w2 = MeasureText( p2, tamFonte );

    DrawText( p1, xc1 - w1/2, y, tamFonte, placar->cor );
    DrawText( p2, xc2 - w2/2, y, tamFonte, placar->cor );

}