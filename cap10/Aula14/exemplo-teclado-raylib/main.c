/**
 * @file exemplo-teclado-raylib/main.c
 * @author Prof. Dr. David Buzatto
 * @brief Exemplos de uso das funções da Raylib relacionadas ao controle
 * do teclado.
 * 
 * @copyright Copyright (c) 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "include/raylib.h"

char caracteres[100] = {0};
int quantidadeCaracteres = 0;

void processarEntrada( void );
void desenhar( void );

int main( void ) {

    SetConfigFlags( FLAG_MSAA_4X_HINT );
    InitWindow( 600, 400, "Exemplo das Funções do Teclado" );
    SetTargetFPS( 60 );

    while ( !WindowShouldClose() ) {
        processarEntrada();
        desenhar();
    }

    CloseWindow();
    return 0;

}

void processarEntrada( void ) {

    /* verifica se uma tecla foi pressionada uma vez
     * bool IsKeyPressed(int key);
     */
    if ( IsKeyPressed( KEY_SPACE ) ) {
        printf( "tecla <espaco> pressionada!\n" );
    }

    /* verifica se uma tecla está pressionada
     * bool IsKeyDown(int key);
     */
    if ( IsKeyDown( KEY_SPACE ) ) {
        printf( "tecla <espaco> continua pressionada!\n" );
    }

    /* verifica se uma tecla foi solta uma vez
     * bool IsKeyReleased(int key);
     */
    if ( IsKeyReleased( KEY_SPACE ) ) {
        printf( "tecla <espaco> solta!\n" );
    }

    /* verifica se uma tecla não está sendo pressionada
     * bool IsKeyUp(int key);
     */

    /* Obtém o código da tecla que foi pressionada.
     * int GetKeyPressed(void);
     */
    int codigo = GetKeyPressed();
    if ( codigo != 0 ) {
        printf( "codigo tecla pressionada: %d\n", codigo );
        if ( codigo == KEY_ENTER ) {
            caracteres[quantidadeCaracteres++] = '\n';
        }
    }

    /* Obtém o caractere da tecla que foi pressionada.
     * int GetCharPressed(void);
     */
    char caractere = GetCharPressed();
    if ( caractere != '\0' ) {
        caracteres[quantidadeCaracteres++] = caractere;
    }

}

void desenhar( void ) {
    
    BeginDrawing();
    ClearBackground( WHITE );

    int x;
    int y = 10;
    int k = 0;

    int tamanhoFonte = 20;

    for ( int i = 0; i < quantidadeCaracteres; i++ ) {
        char caractere = caracteres[i];
        if ( caractere == '\n' ) {
            y += tamanhoFonte;
            k = 0;
        } else {

            x = 10 + k * tamanhoFonte;
            k++;

            DrawText( 
                TextFormat( "%c", caracteres[i] ), 
                x, y, 
                tamanhoFonte, DARKPURPLE );

        }
    }

    EndDrawing();

}