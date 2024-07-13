/**
 * @file GameWorld.h
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld implementation.
 * 
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "GameWorld.h"
#include "ResourceManager.h"

#include "Bola.h"
#include "Jogador.h"
#include "Placar.h"
#include "EstadoJogo.h"
#include "TipoColisao.h"

#include "raylib.h"
//#include "raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raygui.h"              // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h

/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld* createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );

    gw->bola = (Bola){
        .pos = {
            .x = GetScreenWidth() / 2,
            .y = GetScreenHeight() / 2
        },
        .vel = {
            .x = 300,
            .y = 300
        },
        .raio = 10,
        .cor = WHITE,
        .quantidadeSondas = 12,
        .distanciaSondas = 8
    };

    Bola *bola = &gw->bola;

    bola->sondas = (SondaColisao*) malloc( bola->quantidadeSondas * sizeof(SondaColisao) );
    float angulo = 0.0f;
    float incrementoAngulo = 360.0f / bola->quantidadeSondas;
    angulo -= incrementoAngulo;

    Color coresSondas[4] = { BLUE, ORANGE, GREEN, RED };

    for ( int i = 0; i < bola->quantidadeSondas; i++ ) {
        bola->sondas[i] = (SondaColisao){
            .pos = {
                .x = bola->pos.x + bola->distanciaSondas * cosf( DEG2RAD * angulo ),
                .y = bola->pos.y + bola->distanciaSondas * sinf( DEG2RAD * angulo ),
            },
            .raio = 2,
            .cor = coresSondas[i/3]
        };
        angulo += incrementoAngulo;
    }

    int margem = 50;
    int largura = 20;
    int altura = 100;

    gw->jogador1 = (Jogador){
        .ret = {
            .x = margem,
            .y = GetScreenHeight() / 2 - altura / 2,
            .width = largura,
            .height = altura
        },
        .velY = 0,
        .cor = WHITE,
        .pontuacao = 0
    };

    gw->jogador2 = (Jogador){
        .ret = {
            .x = GetScreenWidth() - largura - margem,
            .y = GetScreenHeight() / 2 - altura / 2,
            .width = largura,
            .height = altura
        },
        .velY = 0,
        .cor = WHITE,
        .pontuacao = 0
    };

    gw->placar = (Placar){
        .jogador1 = &gw->jogador1,
        .jogador2 = &gw->jogador2,
        .cor = WHITE
    };

    gw->estado = PARADO;
    gw->ultimoAPontuar = NULL;

    return gw;

}

/**
 * @brief Destroys a GameWindow object and its dependecies.
 */
void destroyGameWorld( GameWorld *gw ) {
    free( gw->bola.sondas );
    free( gw );
}

/**
 * @brief Reads user input and updates the state of the game.
 */
void inputAndUpdateGameWorld( GameWorld *gw ) {

    if ( gw->estado == JOGANDO ) {

        float delta = GetFrameTime();
        int velJogador = (int) ( 300 * delta );

        if ( IsKeyDown( KEY_W ) ) {
            gw->jogador1.velY = -velJogador;
        } else if ( IsKeyDown( KEY_S ) ) {
            gw->jogador1.velY = velJogador;
        } else {
            gw->jogador1.velY = 0;
        }

        if ( IsKeyDown( KEY_UP ) ) {
            gw->jogador2.velY = -velJogador;
        } else if ( IsKeyDown( KEY_DOWN ) ) {
            gw->jogador2.velY = velJogador;
        } else {
            gw->jogador2.velY = 0;
        }

        atualizarBola( &gw->bola );
        atualizarJogador( &gw->jogador1 );
        atualizarJogador( &gw->jogador2 );

        resolverColisaoBolaJogador( &gw->bola, &gw->jogador1 );
        resolverColisaoBolaJogador( &gw->bola, &gw->jogador2 );
        resolverColisaoBolaQuadra( gw );

    } else if ( gw->estado == PARADO ) {

        if ( IsKeyPressed( KEY_ENTER ) ) {

            Bola *bola = &gw->bola;

            if ( gw->ultimoAPontuar == NULL ) {
                if ( GetRandomValue( 0, 1 ) == 0 ) { // jogador 1 começa
                    bola->vel.x = (int) fabs( bola->vel.x );
                } else {
                    bola->vel.x = (int) -fabs( bola->vel.x );
                }
            } else if ( gw->ultimoAPontuar == &gw->jogador1 ) {
                bola->vel.x = (int) fabs( bola->vel.x );
            } else if ( gw->ultimoAPontuar == &gw->jogador2 ) {
                bola->vel.x = (int) -fabs( bola->vel.x );
            }

            if ( GetRandomValue( 0, 1 ) == 0 ) {
                bola->vel.y = (int) fabs( bola->vel.y );
            } else {
                bola->vel.y = (int) -fabs( bola->vel.y );
            }
            gw->estado = JOGANDO;
            
        }

    }

    if ( IsKeyPressed( KEY_F5 ) ) {
        resetarJogo( gw );
    }

}

/**
 * @brief Draws the state of the game.
 */
void drawGameWorld( GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( BLACK );

    int larguraMeio = 8;
    DrawRectangle( 
        GetScreenWidth() / 2 - larguraMeio / 2,
        0,
        larguraMeio,
        GetScreenHeight(),
        WHITE );

    desenharBola( &gw->bola );
    desenharJogador( &gw->jogador1 );
    desenharJogador( &gw->jogador2 );
    desenharPlacar( &gw->placar );

    EndDrawing();

}

void resolverColisaoBolaQuadra( GameWorld *gw ) {

    Bola *bola = &gw->bola;

    // direita da quadra (ponto jogador 1)
    if ( bola->pos.x + bola->raio > GetScreenWidth() ) {
        bola->pos.x = GetScreenWidth() - bola->raio;
        bola->vel.x = -bola->vel.x;
        gw->jogador1.pontuacao++;
        gw->estado = PARADO;
        gw->ultimoAPontuar = &gw->jogador1;
        resetarJogador( &gw->jogador1, false );
        resetarJogador( &gw->jogador2, false );
        resetarPosicaoBola( &gw->bola );
        // esquerda da quadra (ponto jogador 2)
    } else if ( bola->pos.x - bola->raio < 0 ) {
        bola->pos.x = bola->raio;
        bola->vel.x = -bola->vel.x;
        gw->jogador2.pontuacao++;
        gw->estado = PARADO;
        gw->ultimoAPontuar = &gw->jogador2;
        resetarJogador( &gw->jogador1, false );
        resetarJogador( &gw->jogador2, false );
        resetarPosicaoBola( &gw->bola );
    }

    if ( bola->pos.y + bola->raio > GetScreenHeight() ) {
        bola->pos.y = GetScreenHeight() - bola->raio;
        bola->vel.y = -bola->vel.y;
    } else if ( bola->pos.y - bola->raio < 0 ) {
        bola->pos.y = bola->raio;
        bola->vel.y = -bola->vel.y;
    }

}

void resolverColisaoBolaJogador( Bola *bola, Jogador *jogador ) {

    switch ( checarColisaoBolaJogador( bola, jogador ) ) {
        case DIREITA:
            bola->vel.x = (float) -fabs( bola->vel.x );
            break;
        case ESQUERDA:
            bola->vel.x = (float) fabs( bola->vel.x );
            break;
        case CIMA:
            bola->vel.y = (float) fabs( bola->vel.y );
            break;
        case BAIXO:
            bola->vel.y = (float) -fabs( bola->vel.y );
            break;
        case NENHUM:
        default:
            break;
    }

}

void resetarJogo( GameWorld *gw ) {
    resetarPosicaoBola( &gw->bola );
    resetarJogador( &gw->jogador1, true );
    resetarJogador( &gw->jogador2, true );
    gw->ultimoAPontuar = NULL;
    gw->estado = PARADO;
}