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

    int cor;

    printf("Cores disponiveis:\n"
           "\n1) Vermelho\n"
           "2) Verde\n"
           "3) Azul\n");
    printf("\nEscolha uma cor: ");
    scanf("%d", &cor);

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

        switch (cor) {

        case 1:

            DrawRectangle(350, 250, 100, 100, RED);
            break;

        case 2:

            DrawRectangle(350, 250, 100, 100, GREEN);
            break;

        case 3:

            DrawRectangle(350, 250, 100, 100, BLUE);
            break;

        default:

            DrawRectangle(350, 250, 100, 100, YELLOW);
            break;
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
