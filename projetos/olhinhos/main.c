/**
 * @file main.c
 * @author Prof. Dr. David Buzatto
 * @brief Exemplo dos Olhinhos.
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

    // cria uma janela de 600 pixels de largura por 600 de altura
    InitWindow( 600, 600, "Olhinhos" );

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
        int xMouse = GetMouseX();
        int yMouse = GetMouseY();

        int xcOlho1 = 180;
        int ycOlho1 = GetScreenHeight() / 2;
        int raioOlho1 = 100;

        int xcOlho2 = 420;
        int ycOlho2 = GetScreenHeight() / 2;
        int raioOlho2 = 100;

        int catAdjacente1 = xMouse - xcOlho1;
        int catOposto1 = yMouse - ycOlho1;
        float angulo1 = atan2( catOposto1, catAdjacente1 );

        int catAdjacente2 = xMouse - xcOlho2;
        int catOposto2 = yMouse - ycOlho2;
        float angulo2 = atan2( catOposto2, catAdjacente2 );

        int raioIris1 = (int) ( raioOlho1 * 0.5 );
        int distanciaIris1 = (int) ( raioIris1 * 0.7 );
        int xcIris1 = xcOlho1 + distanciaIris1 * cosf( angulo1 );
        int ycIris1 = ycOlho1 + distanciaIris1 * sinf( angulo1 );

        int raioIris2 = (int) ( raioOlho2 * 0.5 );
        int distanciaIris2 = (int) ( raioIris2 * 0.7 );
        int xcIris2 = xcOlho2 + distanciaIris2 * cosf( angulo2 );
        int ycIris2 = ycOlho2 + distanciaIris2 * sinf( angulo2 );

        int raioPupila1 = (int) ( raioIris1 * 0.2 );
        int xcPupila1 = xcIris1;
        int ycPupila1 = ycIris1;

        int raioPupila2 = (int) ( raioIris2 * 0.2 );
        int xcPupila2 = xcIris2;
        int ycPupila2 = ycIris2;

        DrawCircleLines( xcOlho1, ycOlho1, raioOlho1, BLACK );
        DrawCircle( xcIris1, ycIris1, raioIris1, BLUE );
        DrawCircle( xcPupila1, ycPupila1, raioPupila1, BLACK );

        DrawCircleLines( xcOlho2, ycOlho2, raioOlho2, BLACK );
        DrawCircle( xcIris2, ycIris2, raioIris2, BLUE );
        DrawCircle( xcPupila2, ycPupila2, raioPupila2, BLACK );

        /*DrawLine( 0, ycOlho, GetScreenWidth(), ycOlho, BLACK );
        DrawLine( xcOlho, ycOlho, xMouse, yMouse, BLACK );
        DrawLine( xMouse, yMouse, xMouse, ycOlho, BLACK );

        DrawText( TextFormat( "ca: %d, co: %d", catAdjacente, catOposto ), 100, 100, 20, BLACK );
        DrawText( TextFormat( "angulo: %.2f", angulo ), 100, 120, 20, BLACK );*/

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
