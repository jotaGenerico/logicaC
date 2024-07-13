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
     ----------------------------------------------------*/

    int array[5];
    int alvo;
    Color cor = WHITE;

    for(int i = 0; i < 5; i++){
        printf("n%d: ",i + 1);
        scanf("%d", &array[i]);
    }

    printf("buscar por: ");
    scanf("%d", &alvo);

    // ativa a suavização (antialiasing)
    SetConfigFlags( FLAG_MSAA_4X_HINT );

    // cria uma janela de 800 pixels de largura por 600 de altura
    InitWindow( 600, 400, "Título da Janela" );

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

        DrawText(TextFormat("buscando por: %d", alvo), 15, 15, 20, BLACK);

        int posX = 15;
        for (int i = 1; i <= 5; i++) {
            cor = (array[i - 1] == alvo ? BLUE : WHITE);
            DrawRectangle(posX, 40, 80, 90, cor);
            DrawRectangleLines(posX, 40, 80, 90, BLACK);
            posX =  i * 80 + 16;
        }

        posX = 45;
        for (int i = 1; i <= 5; i++) {
            DrawText(TextFormat("%d", array[i-1]), posX, 65, 35, BLACK);
            posX =  i * 80 + 45;
        }

        posX = 45;
        for (int i = 1; i <= 5; i++) {
            DrawText(TextFormat("%d", i-1), posX, 135, 20, BLACK);
            posX =  i * 80 + 45;
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
