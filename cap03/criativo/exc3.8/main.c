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

#include <raylib.h>

int main( void ) {

    /*-----------------------------------------------------
     * A lógica inicial do seu programa deve vir aqui:
     *     - declaração de variáveis;
     *     - entrada de dados;
     *     - processamentos adicionais.
     *     ----------------------------------------------------*/

    int inicioX = 0;
    int finalY = 20;
    int espaco = 20;

    // ativa a suavização (antialiasing)
    SetConfigFlags( FLAG_MSAA_4X_HINT );

    // cria uma janela de 800 pixels de largura por 600 de altura
    InitWindow( 400, 400, "Título da Janela" );

    // configura a quantidade de quatros por segundo da engine
    SetTargetFPS( 60 );

    // enquanto não é sinalizado que a janela deve ser fechada
    while ( !WindowShouldClose() ) {

        // inicia o processo de desenho
        BeginDrawing();

        // limpa a tela usando uma cor
        ClearBackground( WHITE );

        /*----------------------------------------------------------------------
         * A lógica do seu desenho deve vir aqui.
         *         ---------------------------------------------------------------------*/

        for(int i = 0; i < 400; i += espaco){
            DrawLine(inicioX + i, 0 , 400, finalY + i, BLACK);
        }

        /*----------------------------------------------------------------------
         * A lógica do seu desenho deve terminar na linha acima.
         *         ---------------------------------------------------------------------*/

        // termina o desenho
        EndDrawing();

    }

    // fecha a janela
    CloseWindow();
    return 0;

}
