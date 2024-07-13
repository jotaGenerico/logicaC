#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto{

    int x;
    int y;
}Ponto;

typedef struct Retangulo{

    Ponto sup;
    Ponto inf;
}Retangulo;

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir);
void imprimirRetangulo(const Retangulo *r);
void mover(Retangulo *r, int x, int y);

int main(void){

    Retangulo caixa;
    Ponto sup, inf, movido;
    
    printf("Ponto superior esquerdo\n");
    printf("    x: ");
    scanf("%d", &sup.x);
    // funciona scanf("%d", &caixa.s.x);
    printf("    y: ");
    scanf("%d", &sup.y);
    // funciona scanf("%d", &caixa.s.y);

    printf("Ponto inferior direito\n");
    printf("    x: ");
    scanf("%d", &inf.x);
    // funciona scanf("%d", &caixa.i.x);
    printf("    y: ");
    scanf("%d", &inf.y);
    //funciona scanf("%d", &caixa.i.y);

    caixa = novoRetangulo(&sup, &inf);

    printf("Mover em x: ");
    scanf("%d", &movido.x);
    printf("Mover em y: ");
    scanf("%d", &movido.y);

    printf("Retangulo original:\n");
    imprimirRetangulo(&caixa);

    mover(&caixa, movido.x, movido.y);

    printf("Retangulo movido:\n");
    imprimirRetangulo(&caixa);
    

    return 0;
}

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir){
    Retangulo r;

    r.sup = *sEsq;
    r.inf = *iDir;

    return r;
}

void imprimirRetangulo( const Retangulo *r ){
    
    printf("(%+02d, %+02d) =====|\n", r->sup.x, r->sup.y);
    printf("|               |\n");
    printf("|               |\n");
    printf("|===== (%+02d, %+02d)\n", r->inf.x, r->inf.y);
}

void mover(Retangulo *r, int x, int y){

    r->sup.x += x;
    r->inf.x += x;
    r->sup.y += y;
    r->inf.y += y;
}