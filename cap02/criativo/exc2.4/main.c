/**
 * @file main.c
 * @author Prof. Dr. David Buzatto
 * @brief Modelo para desenvolvimento de exercícios criativos usando a engine
 * de jogos Raylib (https://www.raylib.com/).
 *
 * @copyright Copyright (c) 2024
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

int main(void)
{

    /*-----------------------------------------------------
     * A lógica inicial do seu programa deve vir aqui:
     *     - declaração de variáveis;
     *     - entrada de dados;
     *     - processamentos adicionais.
     * ----------------------------------------------------*/

    int celsius;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%d", &celsius);

    // ativa a suavização (antialiasing)
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    // cria uma janela de 800 pixels de largura por 600 de altura
    InitWindow(800, 600, "Título da Janela");

    // configura a quantidade de quatros por segundo da engine
    SetTargetFPS(60);

    // enquanto não é sinalizado que a janela deve ser fechada
    while (!WindowShouldClose()) {

        // inicia o processo de desenho
        BeginDrawing();

        // limpa a tela usando uma cor
        ClearBackground(WHITE);

        /*----------------------------------------------------------------------
         * A lógica do seu desenho deve vir aqui.
         *         ---------------------------------------------------------------------*/

        // primeiro
        DrawRectangleGradientV(50, 250, 350, 125, BLUE, YELLOW);
        DrawRectangleGradientH(50, 250, 350, 125, BLUE, YELLOW);

        // segundo
        DrawRectangleGradientV(400, 250, 350, 125, YELLOW, RED);
        DrawRectangleGradientH(400, 250, 350, 125, YELLOW, RED);

        /*-----------------------------------------------------
         * A lógica do seu desenho deve vir aqui.
         * ----------------------------------------------------*/

        // primeiro
        DrawRectangleGradientV(50, 250, 70, 125, BLUE, YELLOW);
        DrawRectangleGradientH(50, 250, 70, 125, BLUE, YELLOW);

        // segundo
        DrawRectangleGradientV(120, 250, 630, 125, YELLOW, RED);
        DrawRectangleGradientH(120, 250, 630, 125, YELLOW, RED);

        // calculo posiçao
        float proporcao = (celsius + 20) / 200.0f; //proporçao
        int posicaoLinhaX = 50 + proporcao * 700; // posiçao linha

        // linha
        DrawLine(posicaoLinhaX, 250, posicaoLinhaX, 375, BLACK);

        // texto
        char textoCelsius[10];
        sprintf(textoCelsius, "%d", celsius);
        DrawText(textoCelsius, posicaoLinhaX - MeasureText(textoCelsius, 20) / 2, 230, 20, BLACK);

        /*----------------------------------------------------------------------
         * A lógica do seu desenho deve terminar na linha acima.
         * ---------------------------------------------------------------------*/


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
