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

bool intercepta(const Retangulo *r1, const Retangulo *r2);

int main(void){

    Retangulo r1, r2;
    bool cruzam;

    printf("Retangulo 1\n");
    printf("Ponto superior esquerdo\n");
    printf("    x: ");
    scanf("%d", &r1.sup.x);
    printf("    y: ");
    scanf("%d", &r1.sup.y);

    printf("Ponto inferior direito\n");
    printf("    x: ");
    scanf("%d", &r1.inf.x);
    printf("    y: ");
    scanf("%d", &r1.inf.y);

    printf("Retangulo 2\n");
    printf("Ponto superior esquerdo\n");
    printf("    x: ");
    scanf("%d", &r2.sup.x);
    printf("    y: ");
    scanf("%d", &r2.sup.y);

    printf("Ponto inferior direito\n");
    printf("    x: ");
    scanf("%d", &r2.inf.x);
    printf("    y: ");
    scanf("%d", &r2.inf.y);

    cruzam = intercepta(&r1, &r2);
    

    if(cruzam){
        printf("Os retangulos se interceptam!\n");
    }
    else{
        printf("Os retangulos nao se interceptam!\n");
    }

    return 0;
}

bool intercepta(const Retangulo *r1, const Retangulo *r2){

    if(r1->inf.x < r2->sup.x || r2->inf.x < r1->sup.x){
        return false;
    }

    if(r1->sup.x > r2->inf.x || r2->sup.x > r1->inf.x){
        return false;
    }

    if(r1->inf.y > r2->sup.y || r2->inf.y > r1->sup.y){
        return false;
    }

    if(r1->sup.y < r2->inf.y || r2->sup.y < r1->inf.y){
        return false;
    }

    return true;
}