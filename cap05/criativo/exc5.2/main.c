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
void fazerMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, int jogadorAtual);
bool jogoTerminou(int tabuleiro[TABULEIRO][TABULEIRO], int* vencedor);


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

    int vencedor = 0;
    while (!jogoTerminou(tabuleiro, &vencedor)) {
        imprimirTabuleiro();
        printf("Jogador %s, faça sua jogada (ex: A3 B4): ", jogadorAtual == 1 ? "Branco" : "Preto");
        if (scanf(" %c%d %c%d", &colunaOrigem, &linhaOrigem, &colunaDestino, &linhaDestino) != 4) {
            while(getchar() != '\n');
            continue;
        }

        // Converte as entradas para índices do array
        colunaOrigem = (colunaOrigem >= 'a' && colunaOrigem <= 'h') ? colunaOrigem - 'a' : colunaOrigem - 'A';
        colunaDestino = (colunaDestino >= 'a' && colunaDestino <= 'h') ? colunaDestino - 'a' : colunaDestino - 'A';
        linhaOrigem--;
        linhaDestino--;

        if (movimentoValido(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, jogadorAtual)) {
            fazerMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, jogadorAtual);
            jogadorAtual = (jogadorAtual == 1) ? 3 : 1; // Troca o jogador
        } else {
            printf("Movimento inválido. Tente novamente.\n");
        }
    }
    
    printf("\nO Jogo terminou! Vencedor: Jogador %s\n", vencedor == 1 ? "Branco" : "Preto");
    
    // ativa a suavização (antialiasing)
    SetConfigFlags( FLAG_MSAA_4X_HINT );

    // cria uma janela de 800 pixels de largura por 600 de altura
    InitWindow( 800, 600, "Exercício Criativo 5.2 - Damas" );

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

        // 8x8 squares, CASAS = 75
        int CASAS = 75;
        int offsetX = 100;
        int offsetY = 0;
        
        for (int i = 0; i < TABULEIRO; i++) {
            for (int j = 0; j < TABULEIRO; j++) {
                Rectangle quadrado = { offsetX + j * CASAS, offsetY + i * CASAS, CASAS, CASAS };
                Color corQuadrado = ((i + j) % 2 == 0) ? BEIGE : BROWN;
                DrawRectangleRec(quadrado, corQuadrado);

                if (tabuleiro[i][j] != 0) {
                    Vector2 center = { offsetX + j * CASAS + CASAS / 2, offsetY + i * CASAS + CASAS / 2 };
                    bool ehJogador1 = (tabuleiro[i][j] == 1 || tabuleiro[i][j] == 2);
                    Color cor = ehJogador1 ? WHITE : BLACK;
                    DrawCircleV(center, CASAS / 2 - 5, cor);

                    // Indicador de Dama
                    if (tabuleiro[i][j] == 2 || tabuleiro[i][j] == 6) {
                        DrawCircleV(center, CASAS / 4, ehJogador1 ? BLACK : WHITE);
                    }
                }
            }
        }
        
        if (vencedor != 0) {
            DrawText(TextFormat("Vencedor: %s", vencedor == 1 ? "Branco" : "Preto"), 20, 20, 20, DARKGRAY);
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

bool jogoTerminou(int tabuleiro[TABULEIRO][TABULEIRO], int* vencedor) {
    int pecasJogador1 = 0;
    int pecasJogador3 = 0;
    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            if (tabuleiro[i][j] == 1 || tabuleiro[i][j] == 2) pecasJogador1++;
            else if (tabuleiro[i][j] == 3 || tabuleiro[i][j] == 6) pecasJogador3++;
        }
    }
    if (pecasJogador1 == 0) {
        *vencedor = 3;
        return true;
    }
    if (pecasJogador3 == 0) {
        *vencedor = 1;
        return true;
    }
    return false;
}

bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, int jogador) {
    if (linhaOrigem < 0 || linhaOrigem >= TABULEIRO || colunaOrigem < 0 || colunaOrigem >= TABULEIRO) return false;
    if (linhaDestino < 0 || linhaDestino >= TABULEIRO || colunaDestino < 0 || colunaDestino >= TABULEIRO) return false;
    
    int peca = tabuleiro[linhaOrigem][colunaOrigem];
    int rei_val = (jogador == 1) ? 2 : 6;
    if (peca != jogador && peca != rei_val) return false;
    if (tabuleiro[linhaDestino][colunaDestino] != 0) return false;
    
    int direcao = (jogador == 1) ? -1 : 1;
    int dLinha = linhaDestino - linhaOrigem;
    int dColuna = abs(colunaDestino - colunaOrigem);
    bool isDama = (peca == rei_val);

    // Movimento normal
    if ((dLinha == direcao || (isDama && dLinha == -direcao)) && dColuna == 1) return true;

    // Movimento de captura
    if ((dLinha == 2 * direcao || (isDama && dLinha == -2 * direcao)) && dColuna == 2) {
        int linhaCapturada = linhaOrigem + dLinha / 2;
        int colunaCapturada = (colunaDestino + colunaOrigem) / 2;
        int pecaCapturada = tabuleiro[linhaCapturada][colunaCapturada];
        int rei_adv = (jogador == 1) ? 6 : 2;
        int peao_adv = (jogador == 1) ? 3 : 1;
        return (pecaCapturada == peao_adv || pecaCapturada == rei_adv);
    }

    return false;
}

void fazerMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, int jogadorAtual) {
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
        tabuleiro[linhaDestino][colunaDestino] = 2; // Dama branca
    } else if (jogadorAtual == 3 && linhaDestino == TABULEIRO - 1) {
        tabuleiro[linhaDestino][colunaDestino] = 6; // Dama preta
    }
}
