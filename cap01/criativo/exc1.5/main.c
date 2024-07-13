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
     ----------------------------------------------------*/

    int posX;
    int posY;
    int altura;
    int largura;

    printf("Valor do X: ");
    scanf("%d", &posX);

    printf("Valor do Y: ");
    scanf("%d", &posY);

    printf("Valor da altura: ");
    scanf("%d", &altura);

    printf("Valor da largura: ");
    scanf("%d", &largura);

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
         ---------------------------------------------------------------------*/

        DrawRectangle(posX, posY, largura, altura, BLACK);

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
