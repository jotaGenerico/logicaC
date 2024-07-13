#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    float numero;

    printf("Numero: ");
    scanf("%f", &numero);

    if(numero > 0){
        printf("Raiz quadrada de %.2f: %.2f\n", numero, sqrtf(numero));
    }
    else{
        printf("Quadrado de %.2f: %.2f\n", numero, pow(numero, 2));
    }

    return 0;
}