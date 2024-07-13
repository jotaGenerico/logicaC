/**
 * @file exemplo-mouse-raylib/main.c
 * @author Prof. Dr. David Buzatto
 * @brief Exemplos de uso das funções da Raylib relacionadas ao controle
 * do mouse.
 * 
 * @copyright Copyright (c) 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "include/raylib.h"

typedef struct Linha {
    Vector2 ini;
    Vector2 fim;
    bool desenhar;
} Linha;

Linha linhaTemporaria = {0};
Linha linhas[100] = {0};
int quantidadeLinhas = 0;

void processarEntrada( void );
void desenhar( void );
void desenharLinha( Linha *linha );

int main( void ) {

    SetConfigFlags( FLAG_MSAA_4X_HINT );
    InitWindow( 600, 400, "Exemplo das Funções do Mouse" );
    SetTargetFPS( 60 );

    while ( !WindowShouldClose() ) {
        processarEntrada();
        desenhar();
    }

    CloseWindow();
    return 0;

}

void processarEntrada( void ) {

    /* verifica se um botão do mouse foi pressionado uma vez
     * bool IsMouseButtonPressed( int button );
     *
     * principais constantes para representação dos botões:
     * - MOUSE_BUTTON_LEFT: botão da esquerda
     * - MOUSE_BUTTON_MIDDLE: botão do meio
     * - MOUSE_BUTTON_RIGHT: botão da direita
     */
    if ( IsMouseButtonPressed( MOUSE_BUTTON_LEFT ) ) {

        printf( "botao da esquerda pressionado: " );

        /* obtém a posição em x do mouse
         * int GetMouseX( void );
         */

        /* obtém a posição em y do mouse
         * int GetMouseY( void );
         */
        printf( "(%d, %d)\n", GetMouseX(), GetMouseY() );

        linhaTemporaria.ini.x = GetMouseX();
        linhaTemporaria.ini.y = GetMouseY();
        linhaTemporaria.desenhar = false;

    }
    
    /* verifica se um botão do mouse está pressionado
     * bool IsMouseButtonDown( int button );
     */
    if ( IsMouseButtonDown( MOUSE_BUTTON_LEFT ) ) {

        printf( "botao da esquerda continua pressionado!\n" );

        linhaTemporaria.fim.x = GetMouseX();
        linhaTemporaria.fim.y = GetMouseY();
        linhaTemporaria.desenhar = true;

    }

    /* verifica se um botão do mouse foi solto
     * bool IsMouseButtonReleased( int button );
     */
    if ( IsMouseButtonReleased( MOUSE_BUTTON_LEFT ) ) {
        printf( "botao da esquerda solto!\n" );
        linhas[quantidadeLinhas++] = linhaTemporaria;
    }

    /* verifica se um botão do mouse não está sendo pressionado
     * bool IsMouseButtonUp( int button );
     */

}

void desenhar( void ) {
    
    BeginDrawing();
    ClearBackground( WHITE );
    
    if ( linhaTemporaria.desenhar ) {
        desenharLinha( &linhaTemporaria );
    }

    for ( int i = 0; i < quantidadeLinhas; i++ ) {
        desenharLinha( &linhas[i] );
    }

    EndDrawing();

}

void desenharLinha( Linha *linha ) {
    DrawLineV( linha->ini, linha->fim, DARKPURPLE );
}