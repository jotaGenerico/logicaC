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
#define TAMANHO_CELULAS 200

void mostrarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
int verificarVencedor(char tabuleiro[TAMANHO][TAMANHO], char jogador);
int verificarEmpate(char tabuleiro[TAMANHO][TAMANHO]);
void desenharTabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
void jogar();

char tabuleiro[TAMANHO][TAMANHO] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
char jogadorAtual = 'X';
int linha, coluna;

int main( void ) {

    /*-----------------------------------------------------
     * A lógica inicial do seu programa deve vir aqui:
     *     - declaração de variáveis;
     *     - entrada de dados;
     *     - processamentos adicionais.
     ----------------------------------------------------*/


    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        // Considera a margem ao calcular a coluna
        if (mouseX >= 25 && mouseX <= 775) {
            coluna = (mouseX - 25) / 250;
            linha = mouseY / 200;

            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO && tabuleiro[linha][coluna] == ' ') {
                tabuleiro[linha][coluna] = jogadorAtual;

                if (verificarVencedor(tabuleiro, jogadorAtual)) {
                    printf("Jogador %c vence!\n", jogadorAtual);
                    // Reset or exit condition
                }

                if (verificarEmpate(tabuleiro)) {
                    printf("Empate!\n");
                    // Reset or exit condition
                }

                jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
            }
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

        desenharTabuleiro(tabuleiro);

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
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int verificarVencedor(char tabuleiro[TAMANHO][TAMANHO], char jogador) {
    // Verificar linhas
    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return 1;
    }

    // Verificar colunas
    for (int j = 0; j < TAMANHO; j++) {
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador)
            return 1;
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return 1;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return 1;

    return 0;
}

int verificarEmpate(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void desenharTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    int largura = 250;
    int altura = 200;
    int margem = 25;
    int tamanhoFonte = 120;

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            Rectangle cellRect = { margem + j * largura, i * altura, largura, altura };

            DrawRectangleLinesEx(cellRect, 1, BLACK);

            if (tabuleiro[i][j] == 'X') {
                DrawText("X", cellRect.x + (largura / 2) - (tamanhoFonte / 2) + 10, cellRect.y + (altura / 2) - (tamanhoFonte / 2) + 10, tamanhoFonte, RED);
            } else if (tabuleiro[i][j] == 'O') {
                DrawText("O", cellRect.x + (largura / 2) - (tamanhoFonte / 2) + 10, cellRect.y + (altura / 2) - (tamanhoFonte / 2) + 10, tamanhoFonte, BLUE);
            }
        }
    }
}

