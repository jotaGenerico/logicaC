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
    
    float notas[5];
    float maior = 0;
    float menor = 100;
    float total = 0;
    float media = 0;

    for(int i = 0; i < 5; i++){
        printf("nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    for(int i = 0; i < 5; i++){
        maior = (notas[i] >= maior ? notas[i]:maior);
        menor = (notas[i] <= menor ? notas[i]:menor);
        total += notas[i];
    }

    media = total / 5;

    Color corMenor = WHITE;
    Color corMedia = WHITE;
    Color corMaior = WHITE;

    if(menor < 4){
        corMenor = RED;
    }
    else if(menor > 6){
        corMenor = BLUE;
    }
    else{
        corMenor = YELLOW;
    }

    if(media < 4){
        corMedia = RED;
    }
    else if(media > 6){
        corMedia = BLUE;
    }
    else{
        corMedia = YELLOW;
    }

    if(maior < 4){
        corMaior = RED;
    }
    else if(maior > 6){
        corMaior = BLUE;
    }
    else{
        corMaior = YELLOW;
    }

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

        int posX1 = 10;
        int posX2 = 70;
        int posX3 = 130;
        int posY = 300;
        int largura = 50;

        int altura1 = menor * 5;
        int altura2 = media * 5;
        int altura3 = maior * 5;

        // Desenha os retângulos
        DrawRectangle(posX1, posY - altura1, largura, altura1, corMenor);
        DrawRectangle(posX2, posY - altura2, largura, altura2, corMedia);
        DrawRectangle(posX3, posY - altura3, largura, altura3, corMaior);

        // Desenhar o valor das notas acima dos retângulos
        DrawText(TextFormat("%.2f", menor), posX1, posY - 20, 20, BLACK);
        DrawText(TextFormat("%.2f", media), posX2, posY - 20, 20, BLACK);
        DrawText(TextFormat("%.2f", maior), posX3, posY - 20, 20, BLACK);

        DrawText("Menor", posX1, posY + 5, 15, BLACK);
        DrawText("Média", posX2, posY + 5, 15, BLACK);
        DrawText("Maior", posX3, posY + 5, 15, BLACK);

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
