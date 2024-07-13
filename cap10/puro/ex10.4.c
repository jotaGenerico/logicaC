#include <stdio.h>
#include <stdlib.h>

typedef struct Complexo{
    double real;
    double imaginaria;
}Complexo;

Complexo somar(const Complexo *c1, const Complexo *c2);
void imprimirComplexo(const Complexo *c);

int main(void){

    Complexo comp1, comp2, soma;

    printf("Complexo 1\n");
    printf("    Parte real: ");
    scanf("%lf", &comp1.real);
    printf("    Parte imaginaria: ");
    scanf("%lf", &comp1.imaginaria);

    printf("Complexo 2\n");
    printf("    Parte real: ");
    scanf("%lf", &comp2.real);
    printf("    Parte imaginaria: ");
    scanf("%lf", &comp2.imaginaria);

    soma = somar(&comp1, &comp2);

    imprimirComplexo(&comp1);
    printf(" + ");
    imprimirComplexo(&comp2);
    printf(" = ");
    imprimirComplexo(&soma);
    printf("\n");
    
    return 0;
}

Complexo somar(const Complexo *c1, const Complexo *c2){
    Complexo s;
    s.real = c1->real + c2->real;
    s.imaginaria = c1->imaginaria + c2->imaginaria;
    return s;
}

void imprimirComplexo(const Complexo *c){
    printf("(%.2f + %.2fi)", c->real, c->imaginaria);
}