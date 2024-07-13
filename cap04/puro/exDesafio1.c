#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {
    int array[N];
    int pares[N];
    int impares[N];
    int par = 0;
    int impar = 0;

    for (int i = 0; i < N; i++) {
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < N; i++) {
        if (array[i] % 2 == 0) {
            pares[par++] = array[i];
        } else {
            impares[impar++] = array[i];
        }
    }

    for (int i = 0; i < par - 1; i++) {
        for (int j = 0; j < par - i - 1; j++) {
            if (pares[j] > pares[j + 1]) {
                int troca = pares[j];
                pares[j] = pares[j + 1];
                pares[j + 1] = troca;
            }
        }
    }

    for (int i = 0; i < impar - 1; i++) {
        for (int j = 0; j < impar - i - 1; j++) {
            if (impares[j] < impares[j + 1]) {
                int troca = impares[j];
                impares[j] = impares[j + 1];
                impares[j + 1] = troca;
            }
        }
    }

    printf("Valores pares em ordem crescente: ");
    if (par == 0) {
        printf("nao ha.\n");
    } else {
        for (int i = 0; i < par; i++) {
            printf("%d", pares[i]);
            if (i < par - 1) {
                printf(" ");
            }
        }
        printf(".\n");
    }

    printf("Valores impares em ordem decrescente: ");
    if (impar == 0) {
        printf("nao ha.\n");
    } else {
        for (int i = 0; i < impar; i++) {
            printf("%d", impares[i]);
            if (i < impar - 1) {
                printf(" ");
            }
        }
        printf(".\n");
    }

    return 0;
}
