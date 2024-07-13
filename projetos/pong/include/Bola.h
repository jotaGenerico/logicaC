#pragma once

#include <stdbool.h>
#include "Jogador.h"
#include "SondaColisao.h"
#include "TipoColisao.h"
#include "raylib.h"

typedef struct Bola {

    Vector2 pos;
    Vector2 vel;
    int raio;
    Color cor;

    int quantidadeSondas;
    int distanciaSondas;
    SondaColisao *sondas;

} Bola;

void atualizarBola( Bola *bola );
void desenharBola( Bola *bola );
TipoColisao checarColisaoBolaJogador( Bola *bola, Jogador *jogador );
void resetarPosicaoBola( Bola *bola );