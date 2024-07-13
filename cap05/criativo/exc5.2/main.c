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

void DrawBoard();

#define TABULEIRO 8

int tabuleiro[TABULEIRO][TABULEIRO] = {
    {0, 3, 0, 3, 0, 3, 0, 3},
    {3, 0, 3, 0, 3, 0, 3, 0},
    {0, 3, 0, 3, 0, 3, 0, 3},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}
};

void imprimirTabuleiro();
bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, int jogador);
void fazerMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);


int main( void ) {

    /*-----------------------------------------------------
     * A lógica inicial do seu programa deve vir aqui:
     *     - declaração de variáveis;
     *     - entrada de dados;
     *     - processamentos adicionais.
     ----------------------------------------------------*/

    int jogadorAtual = 1; // 1 para brancas, 3 para pretas
    char colunaOrigem, colunaDestino;
    int linhaOrigem, linhaDestino;

    while (1) {
        imprimirTabuleiro();
        printf("Jogador %s, faça sua jogada (ex: A3 B4): ", jogadorAtual == 1 ? "Branco" : "Preto");
        scanf(" %c%d %c%d", &colunaOrigem, &linhaOrigem, &colunaDestino, &linhaDestino);

        // Converte as entradas para índices do array
        colunaOrigem = colunaOrigem - 'A';
        colunaDestino = colunaDestino - 'A';
        linhaOrigem--;
        linhaDestino--;

        if (movimentoValido(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, jogadorAtual)) {
            fazerMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
            jogadorAtual = (jogadorAtual == 1) ? 3 : 1; // Troca o jogador
        } else {
            printf("Movimento inválido. Tente novamente.\n");
        }
    }
    
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

void imprimirTabuleiro() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < TABULEIRO; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < TABULEIRO; j++) {
            switch(tabuleiro[i][j]) {
                case 0: printf(". "); break;
                case 1: printf("b "); break;
                case 2: printf("B "); break;
                case 3: printf("p "); break;
                case 6: printf("P "); break;
            }
        }
        printf("\n");
    }
}

bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, int jogador) {
    // Implemente a lógica de validação de movimento aqui
    // Esta é uma versão simplificada
    if (tabuleiro[linhaOrigem][colunaOrigem] != jogador) return false;
    if (tabuleiro[linhaDestino][colunaDestino] != 0) return false;
    if (abs(linhaDestino - linhaOrigem) != 1 || abs(colunaDestino - colunaOrigem) != 1) return false;
    if (jogador == 1 && linhaDestino >= linhaOrigem) return false;
    if (jogador == 3 && linhaDestino <= linhaOrigem) return false;
    return true;
}

void fazerMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    tabuleiro[linhaDestino][colunaDestino] = tabuleiro[linhaOrigem][colunaOrigem];
    tabuleiro[linhaOrigem][colunaOrigem] = 0;
}
