#include <stdio.h>
#include <stdlib.h>
#include "geom.h"



int main(void){

    Forma retangulo, circulo;
    int moveX, moveY;
    float fator;

    printf("Dados do retangulo:\n");
    printf("  Centro:\n");
    printf("    x: ");
    scanf("%d", &retangulo.centro.x);
    printf("    y: ");
    scanf("%d", &retangulo.centro.y);
    printf("  Largura: ");
    scanf("%d", &retangulo.geom.retangulo.largura);
    printf("  Altura: ");
    scanf("%d", &retangulo.geom.retangulo.altura);
    retangulo.tipo = RETANGULO;

    printf("Dados do circulo:\n");
    printf("  Centro:\n");
    printf("    x: ");
    scanf("%d", &circulo.centro.x);
    printf("    y: ");
    scanf("%d", &circulo.centro.y);
    printf("  Raio: ");
    scanf("%d", &circulo.geom.circulo.raio);
    circulo.tipo = CIRCULO;

    printf("Apos a criacao, mover em:\n");
    printf("  x: ");
    scanf("%d", &moveX);
    printf("  y: ");
    scanf("%d", &moveY);

    printf("Apos mover, redimensionar pelo fator: ");
    scanf("%f", &fator);

    printf("Original:\n");
    imprimirForma(&retangulo);
    imprimirForma(&circulo);

    mover(&retangulo, moveX, moveY);
    mover(&circulo, moveX, moveY);

    printf("\nApos mover:\n");
    imprimirForma(&retangulo);
    imprimirForma(&circulo);

    retangulo = redimensionar(&retangulo, fator);
    circulo = redimensionar(&circulo, fator);

    printf("\nApos redimensionar:\n");
    imprimirForma(&retangulo);
    imprimirForma(&circulo);

    return 0;
}