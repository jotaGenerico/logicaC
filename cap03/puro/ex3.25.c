#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int quantidadeN = 0;
    float somaN = 0;
    float mediaN = 0;
    float n;

    do {
        printf("Entre com um valor: ");
        scanf("%f", &n);

        if(n < 0) {
            break;
        } else {
            quantidadeN++;
            somaN += n;
        }
    } while(n >= 0);

    if(quantidadeN > 0) {
        mediaN = somaN / quantidadeN;
    }

    printf("Somatorio: %.2f\n", somaN);
    printf("Media: %.2f\n", mediaN);
    printf("Quantidade: %d\n", quantidadeN);

    return 0;
}
