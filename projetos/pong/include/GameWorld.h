/**
 * @file GameWorld.h
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld struct and function declarations.
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "Bola.h"
#include "Jogador.h"
#include "Placar.h"
#include "EstadoJogo.h"

typedef struct GameWorld {
    Bola bola;
    Jogador jogador1;
    Jogador jogador2;
    Placar placar;
    EstadoJogo estado;
    Jogador *ultimoAPontuar;
} GameWorld;

/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld* createGameWorld( void );

/**
 * @brief Destroys a GameWindow object and its dependecies.
 */
void destroyGameWorld( GameWorld *gw );

/**
 * @brief Reads user input and updates the state of the game.
 */
void inputAndUpdateGameWorld( GameWorld *gw );

/**
 * @brief Draws the state of the game.
 */
void drawGameWorld( GameWorld *gw );

void resolverColisaoBolaQuadra( GameWorld *gw );
void resolverColisaoBolaJogador( Bola *bola, Jogador *jogador );
void resetarJogo( GameWorld *gw );
