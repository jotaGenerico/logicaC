#pragma once

#include "Jogador.h"
#include "raylib.h"

typedef struct Placar {
    Jogador *jogador1;
    Jogador *jogador2;
    Color cor;
} Placar;

void desenharPlacar( Placar *placar );