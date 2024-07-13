#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Ponto{

    int x;
    int y;
}Ponto;

typedef struct Retangulo{

    Ponto sup;
    Ponto inf;
}Retangulo;

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir);

bool contem(const Retangulo *r, const Ponto *p);

int main(void){

    Retangulo caixa;
    Ponto pontos[5];
    
    printf("Ponto superior esquerdo\n");
    printf("    x: ");
    scanf("%d", &caixa.sup.x);
    printf("    y: ");
    scanf("%d", &caixa.sup.y);

    printf("Ponto inferior direito\n");
    printf("    x: ");
    scanf("%d", &caixa.inf.x);
    printf("    y: ");
    scanf("%d", &caixa.inf.y);

    printf("Pontos\n");
    for(int i=0; i < 5; i++){
        printf("  Ponto %d\n", i+1);
        printf("    x: ");
        scanf("%d", &pontos[i].x);
        printf("    y: ");
        scanf("%d", &pontos[i].y);
    }

    for(int i=0; i < 5; i++){
        printf("(%+02d, %+02d): ", pontos[i].x, pontos[i].y);
        if(contem(&caixa, &pontos[i])){
            printf("contido!");
        }
        else{
            printf("nao contido!");
        }
        printf("\n");
    }

    return 0;
}

bool contem(const Retangulo *r, const Ponto *p){
    bool dentro = true;

    if(p->x < r->sup.x || p->x > r->inf.x){
        dentro = false;
    }

    if(p->y > r->sup.y || p->y < r->inf.y){
        dentro = false;
    }

    return dentro;
}
