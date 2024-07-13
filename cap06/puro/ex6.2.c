#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    float base;
    float expoente;

    printf("Base: ");
    scanf("%f", &base);

    printf("Expoente: ");
    scanf("%f", &expoente);

    printf("%.2f ^ %.2f = %.2f\n", base, expoente, pow(base, expoente));

    return 0;
}
