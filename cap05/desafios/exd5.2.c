#include <stdio.h>
#include <stdlib.h>

#define T 10

void preencherMatriz(int n, int matriz[T][T]);
int determinante(int n, int matriz[T][T]);

int main() {
    int n;
    int matriz[T][T];

    printf("Digite a dimensao da matriz quadrada (entre 2 e 10): ");
    scanf("%d", &n);

    if (n < 2 || n > 10) {
        printf("Dimensao invalida. Deve estar entre 2 e 10.\n");
        return 1;
    }

    preencherMatriz(n, matriz);

    int det = determinante(n, matriz);

    printf("O determinante da matriz eh: %d\n", det);

    return 0;
}

void preencherMatriz(int n, int matriz[T][T]) {
    printf("Preencha a matriz %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int determinante(int n, int matriz[T][T]) {
    if (n == 2) {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }

    int det = 0;
    int submatriz[T][T];

    for (int k = 0; k < n; k++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == k) continue;
                submatriz[subi][subj] = matriz[i][j];
                subj++;
            }
            subi++;
        }
        int sinal = (k % 2 == 0) ? 1 : -1;
        det += sinal * matriz[0][k] * determinante(n - 1, submatriz);
    }

    return det;
}

