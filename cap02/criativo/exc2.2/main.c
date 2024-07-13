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

    int n1, n2, n3;

    printf("N1: ");
    scanf("%d", &n1);

    printf("N2: ");
    scanf("%d", &n2);

    printf("N3: ");
    scanf("%d", &n3);

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

        int posicaoInicialXVela1 = 800 / 2 - 365;
        int posicaoFinalXVela1 = posicaoInicialXVela1 + 50;
        int posicaoInicialXVela2 = posicaoFinalXVela1 + 5;
        int posicaoFinalXVela2 = posicaoInicialXVela2 + 55;
        int posicaoInicialXVela3 = posicaoFinalXVela2 + 5;
        int posicaoFinalXVela3 = posicaoInicialXVela3 + 55;
        int baseY = 600 / 2;
        int escala = 5;

        int menor;
        int medio;
        int maior;
        int tamanhoTexto = 25;

        if (n1 >= n2 && n1 >= n3) {

            maior = n1;

            if (n2 >= n3) {

                medio = n2;
                menor = n3;

            } else {

                medio = n3;
                menor = n2;
            }

        } else if (n2 >= n1 && n2 >= n3) {

            maior = n2;

            if (n1 >= n3) {

                medio = n1;
                menor = n3;

            } else {

                medio = n3;
                menor = n1;
            }
        } else {

            maior = n3;

            if (n1 >= n2) {

                medio = n1;
                menor = n2;

            } else {

                medio = n2;
                menor = n3;
            }
        }

        DrawRectangle(posicaoInicialXVela1, baseY - menor * escala, posicaoFinalXVela1 - posicaoInicialXVela1, menor * escala, SKYBLUE);
        DrawText(TextFormat("%d", menor), posicaoInicialXVela1, baseY + 5, tamanhoTexto, BLACK);

        DrawRectangle(posicaoInicialXVela2, baseY - medio * escala, posicaoFinalXVela2 - posicaoInicialXVela2, medio * escala, BLUE);
        DrawText(TextFormat("%d", medio), posicaoInicialXVela2, baseY + 5, tamanhoTexto, BLACK);

        DrawRectangle(posicaoInicialXVela3, baseY - maior * escala, posicaoFinalXVela3 - posicaoInicialXVela3, maior * escala, DARKBLUE);
        DrawText(TextFormat("%d", maior), posicaoInicialXVela3, baseY + 5, tamanhoTexto, BLACK);

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
