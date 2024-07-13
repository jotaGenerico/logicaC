#include <stdbool.h>
#include "Jogador.h"
#include "raylib.h"

void atualizarJogador( Jogador *jogador ) {

    jogador->ret.y += jogador->velY;

    if ( jogador->ret.y < 0 ) {
        jogador->ret.y = 0;
    } else if ( jogador->ret.y + jogador->ret.height > GetScreenHeight() ) {
        jogador->ret.y = GetScreenHeight() - jogador->ret.height;
    }

}

void desenharJogador( Jogador *jogador ) {
    DrawRectangleRec( jogador->ret, jogador->cor );
}

void resetarJogador( Jogador *jogador, bool resetarPontuacao ) {
    jogador->ret.y = GetScreenHeight() / 2 - jogador->ret.height / 2;
    if ( resetarPontuacao ) {
        jogador->pontuacao = 0;
    }
}