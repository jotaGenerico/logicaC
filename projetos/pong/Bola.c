#include <stdbool.h>
#include <math.h>

#include "Bola.h"
#include "Jogador.h"
#include "TipoColisao.h"
#include "raylib.h"

void atualizarBola( Bola *bola ) {

    float delta = GetFrameTime();

    bola->pos.x += bola->vel.x * delta;
    bola->pos.y += bola->vel.y * delta;

    float angulo = 0.0f;
    float incrementoAngulo = 360.0f / bola->quantidadeSondas;
    angulo -= incrementoAngulo;

    for ( int i = 0; i < bola->quantidadeSondas; i++ ) {
        bola->sondas[i].pos.x = bola->pos.x + bola->distanciaSondas * cosf( DEG2RAD * angulo );
        bola->sondas[i].pos.y = bola->pos.y + bola->distanciaSondas * sinf( DEG2RAD * angulo );
        angulo += incrementoAngulo;
    }

}

void desenharBola( Bola *bola ) {
    DrawCircleV( bola->pos, bola->raio, bola->cor );
    /*for ( int i = 0; i < bola->quantidadeSondas; i++ ) {
        desenharSondaColisao( &bola->sondas[i] );
    }*/
}

TipoColisao checarColisaoBolaJogador( Bola *bola, Jogador *jogador ) {

    for ( int i = 0; i < bola->quantidadeSondas; i++ ) {
        bool colidiu = CheckCollisionCircleRec( 
            bola->sondas[i].pos, 
            bola->sondas[i].raio,
            jogador->ret );
        if ( colidiu ) {
            switch ( i / 3 ) {
                case 0:
                    return DIREITA;
                case 1:
                    return BAIXO;
                case 2:
                    return ESQUERDA;
                case 3:
                    return CIMA;
            }
        }
    }

    return NENHUM;
    
}

void resetarPosicaoBola( Bola *bola ) {
    bola->pos.x = GetScreenWidth() / 2;
    bola->pos.y = GetScreenHeight() / 2;
}