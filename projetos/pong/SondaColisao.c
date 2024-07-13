#include "SondaColisao.h"
#include "raylib.h"

void desenharSondaColisao( SondaColisao *sonda ) {
    DrawCircleV( sonda->pos, sonda->raio, sonda->cor );
}