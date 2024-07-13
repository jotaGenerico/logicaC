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

    int vela1;
    int vela2;

    printf("N1: ");
    scanf("%d", &vela1);

    printf("N2: ");
    scanf("%d", &vela2);

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
         *
         * comentario pessoal, o DrawRectangle desenha sempre para baixo
         * caso venha usalo novamente, lembre do trabalho q foi calcular o final
         * pensando no tamanho q o retangulo teria para o final dele acabar no
         * ponto base q vc queria
         ---------------------------------------------------------------------*/

        int posicaoInicialXVela1 = 800 / 2 - 365;
        int posicaoFinalXVela1 = posicaoInicialXVela1 + 50;
        int posicaoInicialXVela2 = posicaoFinalXVela1 + 5;
        int posicaoFinalXVela2 = posicaoInicialXVela2 + 55;
        int baseY = 600 / 2;
        int escala = 5;

        int tamanhoTexto = 25;

        // vela1
        if (vela1 >= 0) {
            DrawRectangle(posicaoInicialXVela1, baseY - vela1 * escala, posicaoFinalXVela1 - posicaoInicialXVela1, vela1 * escala, GREEN);
            DrawText(TextFormat("%d", vela1), posicaoInicialXVela1, baseY + 5, tamanhoTexto, BLACK);
        } else {
            DrawRectangle(posicaoInicialXVela1, baseY, posicaoFinalXVela1 - posicaoInicialXVela1, -vela1 * escala, RED);
            DrawText(TextFormat("%d", vela1), posicaoInicialXVela1, baseY - 25, tamanhoTexto, BLACK);
        }

        // vela2
        if (vela2 >= 0) {
            DrawRectangle(posicaoInicialXVela2, baseY - vela2 * escala, posicaoFinalXVela2 - posicaoInicialXVela2, vela2 * escala, GREEN);
            DrawText(TextFormat("%d", vela2), posicaoInicialXVela2, baseY + 5, tamanhoTexto, BLACK);
        } else {
            DrawRectangle(posicaoInicialXVela2, baseY, posicaoFinalXVela2 - posicaoInicialXVela2, -vela2 * escala, RED);
            DrawText(TextFormat("%d", vela2), posicaoInicialXVela2, baseY - 25, tamanhoTexto, BLACK);
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
