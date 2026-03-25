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
    
    int lados;
    double raio;

    printf("lados: ");
    scanf("%d", &lados);
    printf("raio: ");
    scanf("%lf", &raio);

    if (lados < 3) {
        printf("Número de lados deve ser maior ou igual a 3.\n");
        return 1;
    }
    
    // ativa a suavização (antialiasing)
    SetConfigFlags( FLAG_MSAA_4X_HINT );

    // cria uma janela de 800 pixels de largura por 600 de altura
    InitWindow( 800, 600, "Exercício Criativo 6.2" );

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

        // Desenhar a circunferência
        DrawCircleLines(centroX, centroY, (float)raio, LIGHTGRAY);

        // Desenhar o polígono usando seno e cosseno
        double anguloIncial = -PI / 2.0; // Começar no topo
        double passo = (2.0 * PI) / lados;

        for (int i = 0; i < lados; i++) {
            double angulo1 = anguloIncial + i * passo;
            double angulo2 = anguloIncial + (i + 1) * passo;

            int x1 = centroX + (int)(raio * cos(angulo1));
            int y1 = centroY + (int)(raio * sin(angulo1));
            int x2 = centroX + (int)(raio * cos(angulo2));
            int y2 = centroY + (int)(raio * sin(angulo2));

            DrawLine(x1, y1, x2, y2, RED);
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
