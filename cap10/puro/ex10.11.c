#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto{

    int x;
    int y;
}Ponto;

typedef struct Retangulo{

    Ponto sEsq;
    Ponto iDir;
}Retangulo;

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir);
int calcularArea(const Retangulo *r);
void imprimirRetangulo(const Retangulo *r);

int main(void){

    Retangulo caixa;
    Ponto superior, inferior;
    int area;

    printf("Ponto superior esquerdo\n");
    printf("    x: ");
    scanf("%d", &superior.x);
    printf("    y: ");
    scanf("%d", &superior.y);

    printf("Ponto inferior direito\n");
    printf("    x: ");
    scanf("%d", &inferior.x);
    printf("    y: ");
    scanf("%d", &inferior.y);
    
    caixa = novoRetangulo(&superior, &inferior);
    area = calcularArea(&caixa);

    imprimirRetangulo(&caixa);
    printf("Area: %04d\n", area);

    return 0;
}

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir){
    Retangulo r;
    r.sEsq = *sEsq;
    r.iDir = *iDir;

    return r; 
}

int calcularArea(const Retangulo *r){
    int largura = r->iDir.x - r->sEsq.x;
    int altura = r->sEsq.y - r->iDir.y;

    return largura * altura;
}

void imprimirRetangulo(const Retangulo *r){
    
    printf("(%+02d, %+02d) =====|\n", r->sEsq.x, r->sEsq.y);
    printf("|               |\n");
    printf("|               |\n");
    printf("|===== (%+02d, %+02d)\n", r->iDir.x, r->iDir.y);
}