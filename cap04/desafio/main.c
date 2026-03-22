#include <stdio.h>

int main(void) {

    int array[10];
    int pares[10], impares[10];
    int nPares = 0, nImpares = 0;
    int i, j, chave;

    for (i = 0; i < 10; i++) {
        printf("array[%d]:", i);
        if (scanf("%d", &array[i]) != 1) return 1;

        if (array[i] % 2 == 0) {
            pares[nPares++] = array[i];
        } else {
            impares[nImpares++] = array[i];
        }
    }

    for (i = 1; i < nPares; i++) {
        chave = pares[i];
        j = i - 1;

        while (j >= 0 && pares[j] > chave) {
            pares[j + 1] = pares[j];
            j--;
        }
        pares[j + 1] = chave;
    }

    for (i = 1; i < nImpares; i++) {
        chave = impares[i];
        j = i - 1;

        while (j >= 0 && impares[j] < chave) {
            impares[j + 1] = impares[j];
            j--;
        }
        impares[j + 1] = chave;
    }

    printf("Valores pares em ordem crescente: ");
    if (nPares == 0) {
        printf("nao ha.\n");
    } else {
        for (i = 0; i < nPares; i++) {
            printf("%d%s", pares[i], (i == nPares - 1) ? ".\n" : " ");
        }
    }

    printf("Valores impares em ordem decrescente: ");
    if (nImpares == 0) {
        printf("nao ha.\n");
    } else {
        for (i = 0; i < nImpares; i++) {
            printf("%d%s", impares[i], (i == nImpares - 1) ? ".\n" : " ");
        }
    }

    return 0;
}
