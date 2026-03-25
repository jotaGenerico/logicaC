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

int main( void ) {

    /*-----------------------------------------------------
     * A lógica inicial do seu programa deve vir aqui:
     *     - declaração de variáveis;
     *     - entrada de dados;
     *     - processamentos adicionais.
     ----------------------------------------------------*/
    
    
    // ativa a suavização (antialiasing)
    SetConfigFlags( FLAG_MSAA_4X_HINT );

    // cria uma janela de 800 pixels de largura por 600 de altura
    InitWindow( 800, 600, "Exercício Criativo 6.1" );

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
         ---------------------------------------------------------------------*/

        DrawLine(0, 300, 800, 300, LIGHTGRAY);
        DrawLine(400, 0, 400, 600, LIGHTGRAY);

        int amplitude = 100;
        int frequencia = 50; // pixels por radiano

        for ( int x = 0; x < 800; x++ ) {
            double angulo = (double)(x - 400) / frequencia;
            
            // Seno (Azul)
            double ySeno = sin(angulo);
            int telaYSeno = 300 - (int)(ySeno * amplitude);
            DrawCircle(x, telaYSeno, 2, BLUE);

            // Cosseno (Roxo)
            double yCosseno = cos(angulo);
            int telaYCosseno = 300 - (int)(yCosseno * amplitude);
            DrawCircle(x, telaYCosseno, 2, PURPLE);
        }

        /*----------------------------------------------------------------------
         * A lógica do seu desenho deve terminar na linha acima.
         ---------------------------------------------------------------------*/

        // termina o desenho
        EndDrawing();

    }

    // fecha a janela
    CloseWindow();
    return 0;

}
