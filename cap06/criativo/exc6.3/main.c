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
    Color cores[7] = { RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, MAGENTA };
    
    // ativa a suavização (antialiasing)
    SetConfigFlags( FLAG_MSAA_4X_HINT );

    // cria uma janela de 800 pixels de largura por 600 de altura
    InitWindow( 800, 600, "Exercício Criativo 6.3" );

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
         
        int centroX = 400;
        int centroY = 300;
        double raioInicial = 150.0;
        double incrementoRaio = 5.0;

        for (int lados = 3; lados <= 9; lados++) {
            double raioAtual = raioInicial + (lados - 3) * incrementoRaio;
            Color corAtual = cores[lados - 3];

            double anguloIncial = -PI / 2.0;
            double passo = (2.0 * PI) / lados;

            for (int i = 0; i < lados; i++) {
                double angulo1 = anguloIncial + i * passo;
                double angulo2 = anguloIncial + (i + 1) * passo;

                int x1 = centroX + (int)(raioAtual * cos(angulo1));
                int y1 = centroY + (int)(raioAtual * sin(angulo1));
                int x2 = centroX + (int)(raioAtual * cos(angulo2));
                int y2 = centroY + (int)(raioAtual * sin(angulo2));

                DrawLine(x1, y1, x2, y2, corAtual);
            }
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
