#include <stdio.h>
#include <stdlib.h>

typedef struct Fracao{
    float numerador, denominador;
}Fracao;

Fracao somar(const Fracao *f1, const Fracao *f2);
Fracao subtrair(const Fracao *f1, const Fracao *f2);
Fracao multiplicar(const Fracao *f1, const Fracao *f2);
Fracao dividir(const Fracao *f1, const Fracao *f2);
void imprimirFracao(const Fracao *f);

int main(void){
    
    Fracao fracao1, fracao2, resultado;

    printf("Fracao 1\n");
    printf("    Numerador: ");
    scanf("%f", &fracao1.numerador);
    printf("    Denominador: ");
    scanf("%f", &fracao1.denominador);

    printf("Fracao 2\n");
    printf("    Numerador: ");
    scanf("%f", &fracao2.numerador);
    printf("    Denominador: ");
    scanf("%f", &fracao2.denominador);

    resultado = somar(&fracao1, &fracao2);
    imprimirFracao(&fracao1);
    printf(" + ");
    imprimirFracao(&fracao2);
    printf(" = ");
    imprimirFracao(&resultado);
    printf("\n");

    resultado = subtrair(&fracao1, &fracao2);
    imprimirFracao(&fracao1);
    printf(" - ");
    imprimirFracao(&fracao2);
    printf(" = ");
    imprimirFracao(&resultado);
    printf("\n");

    resultado = multiplicar(&fracao1, &fracao2);
    imprimirFracao(&fracao1);
    printf(" * ");
    imprimirFracao(&fracao2);
    printf(" = ");
    imprimirFracao(&resultado);
    printf("\n");

    resultado = dividir(&fracao1, &fracao2);
    imprimirFracao(&fracao1);
    printf(" / ");
    imprimirFracao(&fracao2);
    printf(" = ");
    imprimirFracao(&resultado);
    printf("\n");

    return 0;
}

Fracao somar(const Fracao *f1, const Fracao *f2){
    Fracao resultado;
    resultado.numerador = f1->numerador * f2->denominador + f2->numerador * f1->denominador;
    resultado.denominador = f1->denominador * f2->denominador;
    return resultado;
}

Fracao subtrair(const Fracao *f1, const Fracao *f2){
    Fracao resultado;
    resultado.numerador = f1->numerador * f2->denominador - f2->numerador * f1->denominador;
    resultado.denominador = f1->denominador * f2->denominador;
    return resultado;
}
Fracao multiplicar(const Fracao *f1, const Fracao *f2){
    Fracao resultado;
    resultado.numerador = f1->numerador * f2->numerador;
    resultado.denominador = f1->denominador * f2->denominador;
    return resultado;
}
Fracao dividir(const Fracao *f1, const Fracao *f2){
    Fracao resultado;
    resultado.numerador = f1->numerador * f2->denominador;
    resultado.denominador = f1->denominador * f2->numerador;
    return resultado;
}

void imprimirFracao(const Fracao *f){
    printf("%.2f/%.2f", f->numerador, f->denominador);
};