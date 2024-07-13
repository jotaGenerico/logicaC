#pragma once

#include "raygui.h"

typedef struct SondaColisao {
    Vector2 pos;
    int raio;
    Color cor;
} SondaColisao;

void desenharSondaColisao( SondaColisao *sonda );