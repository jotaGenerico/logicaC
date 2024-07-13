#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

float areaCirculo(float raio);
float circunferenciaCirculo(float raio);

int main(void){

    float raio;

    printf("Raio: ");
    scanf("%f", &raio);

    printf("Area = %.2f\n", areaCirculo(raio));
    printf("Circunferencia = %.2f\n", circunferenciaCirculo(raio));

    return 0;
}

float areaCirculo(float raio){
    return PI * (raio * raio);
}

float circunferenciaCirculo(float raio){
    float circunferencia;

    circunferencia = 2 * PI * raio;

    return circunferencia;
}