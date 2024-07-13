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

    int espaco = 20;

    //primeiro
    int iPrimeiroX = 0;
    int fPrimeiroX = 20;
    int iPrimeiroY = 0;
    int fPrimeiroY = 20;

    //segundo
    int iSegundoX = 0;
    int fSegundoX = 20;
    int iSegundoY = 400;
    int fSegundoY = 380;


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


        //superior direito
        for(int i = 0; i < 400; i += 20){
            DrawLine(iPrimeiroX + i, 0 , 400, fPrimeiroY + i, BLUE);
        }

        //inferior esquerdo
        for(int i = 0; i < 400; i += 20){
            DrawLine(0, iPrimeiroY + i, fPrimeiroX + i, 400, RED);
        }

        //superior esquerdo
        for (int i = 0; i < 400 ; i += 20) {
            DrawLine(0, fSegundoX + i, iSegundoY - i, 0, ORANGE);
        }

        //inferior direito
        for (int i = 0; i < 400 ; i += 20) {
            DrawLine(iSegundoX + i, 400, 400, fSegundoY - i, GREEN);
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
