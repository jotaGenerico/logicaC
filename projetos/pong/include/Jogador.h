#pragma once

#include <stdbool.h>
#include "raylib.h"

typedef struct Jogador {
    Rectangle ret;
    int velY;
    Color cor;
    int pontuacao;
} Jogador;

void atualizarJogador( Jogador *jogador );
void desenharJogador( Jogador *jogador );
void resetarJogador( Jogador *jogador, bool resetarPontuacao );