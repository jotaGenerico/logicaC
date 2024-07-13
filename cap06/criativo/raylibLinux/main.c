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

#define T 10

void preencherMatriz(int linhas, int colunas, int matriz[T][T]);
void multiplicarMatrizes(int m, int n, int p, int A[T][T], int B[T][T], int C[T][T]);
void exibirMatriz(int linhas, int colunas, int matriz[T][T]);

int main( void ) {

    /*-----------------------------------------------------
     * A lógica inicial do seu programa deve vir aqui:
     *     - declaração de variáveis;
     *     - entrada de dados;
     *     - processamentos adicionais.
     ----------------------------------------------------*/

    int m, n, p;
    int A[T][T], B[T][T], C[T][T];

    printf("Digite as dimensões da primeira matriz (m x n):\n");
    printf("Linhas: ");
    scanf("%d", &m);
    printf("Colunas: ");
    scanf("%d", &n);
    printf("Digite as dimensões da segunda matriz (n x p): \n");
    printf("Linhas: ");
    scanf("%d", &p);
    printf("Colunas: ");
    scanf("%d", &p);

    if (m < 1 || m > 10 || n < 1 || n > 10 || p < 1 || p > 10) {
        printf("Dimensoes invalidas. Devem estar entre 1 e 10.\n");
        return 1;
    }

    preencherMatriz(m, n, A);
    preencherMatriz(n, p, B);

    multiplicarMatrizes(m, n, p, A, B, C);
    
    // ativa a suavização (antialiasing)
    SetConfigFlags( FLAG_MSAA_4X_HINT );

    // cria uma janela de 800 pixels de largura por 600 de altura
    InitWindow( 800, 600, "Título da Janela" );

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

        int tamanhoElemento = 80;
        int espacamentoHorizontal = 40;
        int espacamentoVertical = 20;

        int matrizWidth = p * (tamanhoElemento + espacamentoHorizontal) - espacamentoHorizontal;
        int matrizHeight = m * (tamanhoElemento + espacamentoVertical) - espacamentoVertical;

        int posX = (GetScreenWidth() - matrizWidth) / 2;
        int posY = (GetScreenHeight() - matrizHeight) / 2;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                DrawText(TextFormat(" [%04d] ", C[i][j]), posX + espacamentoHorizontal + (tamanhoElemento + espacamentoHorizontal) * j, posY + espacamentoVertical + (tamanhoElemento + espacamentoVertical) * i, 40, BLACK);
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

void preencherMatriz(int linhas, int colunas, int matriz[T][T]) {
    printf("Preencha a matriz %dx%d:\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("[%d][%d]", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void multiplicarMatrizes(int m, int n, int p, int A[T][T], int B[T][T], int C[T][T]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
