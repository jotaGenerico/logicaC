#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    float numero;

    printf("Numero: ");
    scanf("%f", &numero);
    printf("Valor absoluto: %.2f\n", fabs(numero));

    return 0;
}