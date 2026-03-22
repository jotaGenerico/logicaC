/**
 * @file main.c
 * @author Prof. Dr. David Buzatto
 * @brief Modelo para desenvolvimento de exercícios criativos usando a engine
 * de jogos Raylib (https://www.raylib.com/).
 * * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>

#define TAMANHO 3

// Protótipos
void mostrarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
int verificarVencedor(char tabuleiro[TAMANHO][TAMANHO], char jogador);
int verificarEmpate(char tabuleiro[TAMANHO][TAMANHO]);
void desenharTabuleiro(char tabuleiro[TAMANHO][TAMANHO]);

// Variáveis Globais
char tabuleiro[TAMANHO][TAMANHO] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
char jogadorAtual = 'X';
bool fimDeJogo = false;

int main( void ) {

    /*-----------------------------------------------------
     * A lógica inicial do seu programa deve vir aqui:
     * - declaração de variáveis;
     * - entrada de dados;
     * - processamentos adicionais.
     ----------------------------------------------------*/

    SetConfigFlags( FLAG_MSAA_4X_HINT );
    InitWindow( 800, 600, "Exercício Criativo 5.2 - Mouse" );
    SetTargetFPS( 60 );

    while ( !WindowShouldClose() ) {

        /*----------------------------------------------------------------------
         * Atualização da Lógica (Interação com a Matriz via Mouse)
         ---------------------------------------------------------------------*/

        if (!fimDeJogo && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            // Cálculo para mapear o clique na matriz (considerando a tua função desenharTabuleiro)
            // Largura da célula: 250, Altura: 200, Margem: 25
            if (mouseX >= 25 && mouseX <= 775) {
                int coluna = (mouseX - 25) / 250;
                int linha = mouseY / 200;

                if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                    if (tabuleiro[linha][coluna] == ' ') {
                        tabuleiro[linha][coluna] = jogadorAtual;

                        if (verificarVencedor(tabuleiro, jogadorAtual)) {
                            fimDeJogo = true;
                        } else if (verificarEmpate(tabuleiro)) {
                            fimDeJogo = true;
                        } else {
                            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
                        }
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground( WHITE );

        /*----------------------------------------------------------------------
         * A lógica do seu desenho deve vir aqui.
         ---------------------------------------------------------------------*/

        desenharTabuleiro(tabuleiro);

        if (fimDeJogo) {
            DrawText("FIM DE JOGO", 300, 550, 30, DARKGRAY);
        }

        /*----------------------------------------------------------------------
         * A lógica do seu desenho deve terminar na linha acima.
         ---------------------------------------------------------------------*/

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

/*----------------------------------------------------------------------
 * Funções de Lógica e Desenho
 ---------------------------------------------------------------------*/

void desenharTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    int largura = 250;
    int altura = 200;
    int margem = 25;

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            Rectangle cellRect = { margem + j * largura, i * altura, largura, altura };
            DrawRectangleLinesEx(cellRect, 2, BLACK);

            if (tabuleiro[i][j] != ' ') {
                DrawText(TextFormat("%c", tabuleiro[i][j]),
                         margem + j * largura + 80, i * altura + 40, 120,
                         (tabuleiro[i][j] == 'X') ? RED : BLUE);
            }
        }
    }
}

int verificarVencedor(char tabuleiro[TAMANHO][TAMANHO], char jogador) {
    for (int i = 0; i < TAMANHO; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador))
            return 1;
    }
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador))
        return 1;
    return 0;
}

int verificarEmpate(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++)
            if (tabuleiro[i][j] == ' ') return 0;
    return 1;
}
