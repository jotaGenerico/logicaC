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

#define TAMANHO 3

char tabuleiro[TAMANHO][TAMANHO] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
char jogadorAtual = 'X';

void mostrarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
bool verificarVencedor(char tabuleiro[TAMANHO][TAMANHO], char jogador);
bool verificarEmpate(char tabuleiro[TAMANHO][TAMANHO]);
void jogar();


int main( void ) {

    /*-----------------------------------------------------
     * A lógica inicial do seu programa deve vir aqui:
     *     - declaração de variáveis;
     *     - entrada de dados;
     *     - processamentos adicionais.
     ----------------------------------------------------*/

    jogar();

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

        mostrarTabuleiro(tabuleiro);

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


void mostrarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAMANHO - 1) printf("|");
        }
        printf("\n");
        if (i < TAMANHO - 1) printf("---|---|---\n");
    }
}

bool verificarVencedor(char tabuleiro[TAMANHO][TAMANHO], char jogador) {
    // Verificar linhas
    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return true;
    }

    // Verificar colunas
    for (int j = 0; j < TAMANHO; j++) {
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador)
            return true;
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return true;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return true;

    return false;
}

bool verificarEmpate(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void jogar() {
    int linha, coluna;
    bool fimDeJogo = false;

    while (!fimDeJogo) {
        mostrarTabuleiro(tabuleiro);
        printf("Jogador %c, entre com a linha e coluna (0-2) separadas por espaço: ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogadorAtual;

            if (verificarVencedor(tabuleiro, jogadorAtual)) {
                mostrarTabuleiro(tabuleiro);
                printf("Jogador %c vence!\n", jogadorAtual);
                fimDeJogo = true;
            } else if (verificarEmpate(tabuleiro)) {
                mostrarTabuleiro(tabuleiro);
                printf("Empate!\n");
                fimDeJogo = true;
            } else {
                jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Jogada inválida! Tente novamente.\n");
        }
    }
}

