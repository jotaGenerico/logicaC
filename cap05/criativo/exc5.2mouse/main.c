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

#define TABULEIRO 8
#define CASAS 75

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

int jogadorAtual = 1; // 1 para brancas, 3 para pretas
Vector2 pecaSelecionada = {-1, -1};
Vector2 movimentoPossivel = {-1, -1};

void DrawBoard();
bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, int jogador);
void fazerMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);

int main( void ) {

    /*-----------------------------------------------------
     * A lógica inicial do seu programa deve vir aqui:
     *     - declaração de variáveis;
     *     - entrada de dados;
     *     - processamentos adicionais.
     ----------------------------------------------------*/
    
    
    // ativa a suavização (antialiasing)
    SetConfigFlags( FLAG_MSAA_4X_HINT );

    // cria uma janela de 800 pixels de largura por 600 de altura
    InitWindow(TABULEIRO * CASAS, TABULEIRO * CASAS, "Jogo de Damas");

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

        DrawBoard();

        Vector2 mousePos = GetMousePosition();
        int linhaMouse = mousePos.y / CASAS;
        int colunaMouse = mousePos.x / CASAS;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (pecaSelecionada.x == -1) {
                if (tabuleiro[linhaMouse][colunaMouse] == jogadorAtual ||
                    tabuleiro[linhaMouse][colunaMouse] == jogadorAtual + 1) {
                    pecaSelecionada = (Vector2){linhaMouse, colunaMouse};
                    }
            } else {
                if (movimentoValido(pecaSelecionada.x, pecaSelecionada.y, linhaMouse, colunaMouse, jogadorAtual)) {
                    fazerMovimento(pecaSelecionada.x, pecaSelecionada.y, linhaMouse, colunaMouse);
                    jogadorAtual = (jogadorAtual == 1) ? 3 : 1;
                }
                pecaSelecionada = (Vector2){-1, -1};
                movimentoPossivel = (Vector2){-1, -1};
            }
        }

        if (pecaSelecionada.x != -1) {
            movimentoPossivel = (Vector2){-1, -1};
            if (movimentoValido(pecaSelecionada.x, pecaSelecionada.y, linhaMouse, colunaMouse, jogadorAtual)) {
                movimentoPossivel = (Vector2){linhaMouse, colunaMouse};
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

void DrawBoard() {
    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            Rectangle quadrado = { j * CASAS, i * CASAS, CASAS, CASAS };
            Color corQuadrado = ((i + j) % 2 == 0) ? BEIGE : BROWN;

            if ((int)pecaSelecionada.x == i && (int)pecaSelecionada.y == j) {
                corQuadrado = YELLOW;
            } else if ((int)movimentoPossivel.x == i && (int)movimentoPossivel.y == j) {
                corQuadrado = GREEN;
            }

            DrawRectangleRec(quadrado, corQuadrado);

            if (tabuleiro[i][j] != 0) {
                Vector2 center = { j * CASAS + CASAS / 2, i * CASAS + CASAS / 2 };
                bool ehJogador1 = (tabuleiro[i][j] == 1 || tabuleiro[i][j] == 2);
                Color cor = ehJogador1 ? WHITE : BLACK;
                DrawCircleV(center, CASAS / 2 - 5, cor);

                if (tabuleiro[i][j] == 2 || tabuleiro[i][j] == 4) {
                    DrawCircleV(center, CASAS / 4, ehJogador1 ? BLACK : WHITE);
                }
            }
        }
    }
}

bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, int jogador) {
    if (tabuleiro[linhaOrigem][colunaOrigem] != jogador && tabuleiro[linhaOrigem][colunaOrigem] != jogador + 1) return false;
    if (tabuleiro[linhaDestino][colunaDestino] != 0) return false;
    int direcao = (jogador == 1) ? -1 : 1;
    int dLinha = linhaDestino - linhaOrigem;
    int dColuna = abs(colunaDestino - colunaOrigem);

    // Movimento normal
    if (dLinha == direcao && dColuna == 1) return true;

    // Movimento de captura
    if (dLinha == 2 * direcao && dColuna == 2) {
        int linhaCapturada = linhaOrigem + direcao;
        int colunaCapturada = (colunaDestino + colunaOrigem) / 2;
        int pecaCapturada = tabuleiro[linhaCapturada][colunaCapturada];
        return (pecaCapturada != 0 && pecaCapturada != jogador && pecaCapturada != jogador + 1);
    }

    return false;
}

void fazerMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    tabuleiro[linhaDestino][colunaDestino] = tabuleiro[linhaOrigem][colunaOrigem];
    tabuleiro[linhaOrigem][colunaOrigem] = 0;

    // Captura
    if (abs(linhaDestino - linhaOrigem) == 2) {
        int linhaCapturada = (linhaDestino + linhaOrigem) / 2;
        int colunaCapturada = (colunaDestino + colunaOrigem) / 2;
        tabuleiro[linhaCapturada][colunaCapturada] = 0;
    }

    // Promoção a dama
    if (jogadorAtual == 1 && linhaDestino == 0) {
        tabuleiro[linhaDestino][colunaDestino] = 2;
    } else if (jogadorAtual == 3 && linhaDestino == TABULEIRO - 1) {
        tabuleiro[linhaDestino][colunaDestino] = 6;
    }
}
