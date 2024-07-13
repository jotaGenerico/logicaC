/**
 * @file main.c
 * @author Prof. Dr. David Buzatto
 * @brief Modelo para desenvolvimento de exercícios criativos usando a engine
 * de jogos Raylib (https://www.raylib.com/).
 * 
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <raylib.h>

const float GRAVIDADE = 50;
Vector2 offset;
Vector2 mousePosAnt;

typedef struct Bolinha {
    Vector2 pos;
    Vector2 vel;
    float atrito;
    float elasticidade;
    int raio;
    Color cor;
    bool arrastando;
} Bolinha;

void atualizar( Bolinha *bolinha );
void desenhar( Bolinha *bolinha );
bool intercepta( Bolinha *bolinha, Vector2 *pos );

int main( void ) {
    
    // ativa a suavização (antialiasing)
    SetConfigFlags( FLAG_MSAA_4X_HINT );

    // cria uma janela de 800 pixels de largura por 600 de altura
    InitWindow( 800, 600, "Bolinha" );

    // configura a quantidade de quatros por segundo da engine
    SetTargetFPS( 60 );    

    Bolinha bolinha = {
        .pos = {
            .x = GetScreenWidth() / 2,
            .y = GetScreenHeight() / 2,
        },
        .vel = {
            .x = 300,
            .y = 300
        },
        .atrito = 0.99,
        .elasticidade = 0.9,
        .raio = 50,
        .cor = BLUE,
        .arrastando = false
    };

    // enquanto não é sinalizado que a janela deve ser fechada
    while ( !WindowShouldClose() ) {
        atualizar( &bolinha );
        desenhar( &bolinha );
    }

    // fecha a janela
    CloseWindow();
    return 0;

}

void atualizar( Bolinha *bolinha ) {

    float delta = GetFrameTime();

    if ( IsMouseButtonPressed( MOUSE_BUTTON_LEFT ) ) {
        Vector2 mousePos = GetMousePosition();
        if ( intercepta( bolinha, &mousePos ) ) {
            bolinha->arrastando = true;
            offset.x = mousePos.x - bolinha->pos.x;
            offset.y = mousePos.y - bolinha->pos.y;
        }
    } else if ( IsMouseButtonReleased( MOUSE_BUTTON_LEFT ) ) {
        bolinha->arrastando = false;
    }

    if ( !bolinha->arrastando ) {

        bolinha->pos.x += bolinha->vel.x * delta;
        bolinha->pos.y += bolinha->vel.y * delta;

        if ( bolinha->pos.x + bolinha->raio >= GetScreenWidth() ) {
            bolinha->pos.x = GetScreenWidth() - bolinha->raio;
            bolinha->vel.x = -bolinha->vel.x * bolinha->elasticidade;
        } else if ( bolinha->pos.x - bolinha->raio <= 0 ) {
            bolinha->pos.x = bolinha->raio;
            bolinha->vel.x = -bolinha->vel.x * bolinha->elasticidade;
        }

        if ( bolinha->pos.y + bolinha->raio >= GetScreenHeight() ) {
            bolinha->pos.y = GetScreenHeight() - bolinha->raio;
            bolinha->vel.y = -bolinha->vel.y * bolinha->elasticidade;
        } else if ( bolinha->pos.y - bolinha->raio <= 0 ) {
            bolinha->pos.y = bolinha->raio;
            bolinha->vel.y = -bolinha->vel.y * bolinha->elasticidade;
        }

        bolinha->vel.x = bolinha->vel.x * bolinha->atrito;
        bolinha->vel.y = bolinha->vel.y * bolinha->atrito + GRAVIDADE;

    } else {

        Vector2 mousePos = GetMousePosition();
        bolinha->pos.x = mousePos.x - offset.x;
        bolinha->pos.y = mousePos.y - offset.y;

        bolinha->vel.x = ( mousePos.x - mousePosAnt.x ) * 50;
        bolinha->vel.y = ( mousePos.y - mousePosAnt.y ) * 50;

        mousePosAnt = mousePos;

    }

}

void desenhar( Bolinha *bolinha ) {

    BeginDrawing();
    ClearBackground( WHITE );

    DrawCircle( bolinha->pos.x, bolinha->pos.y, bolinha->raio, bolinha->cor );

    EndDrawing();

}

bool intercepta( Bolinha *bolinha, Vector2 *pos ) {

    float distancia = hypotf( bolinha->pos.x - pos->x, bolinha->pos.y - pos->y );

    if ( distancia > bolinha->raio ) {
        return false;
    }

    return true;

}
