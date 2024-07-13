#include <stdio.h>
#include <stdlib.h>

#define T 10

void preencherMatriz(int linhas, int colunas, int matriz[T][T]);
void multiplicarMatrizes(int m, int n, int p, int A[T][T], int B[T][T], int C[T][T]);
void exibirMatriz(int linhas, int colunas, int matriz[T][T]);

int main() {
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

    printf("Resultado da multiplicacao:\n");
    exibirMatriz(m, p, C);

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

void exibirMatriz(int linhas, int colunas, int matriz[T][T]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%04d ", matriz[i][j]);
        }
        printf("\n");
    }
}
