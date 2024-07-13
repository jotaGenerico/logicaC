#include <stdio.h>
#include <stdlib.h>

typedef struct Cor{
    int vermelho;
    int verde;
    int azul;
}Cor;

Cor novaCor(int vermelho, int verde, int azul);
void imprimirCor(const Cor *c);
Cor clarear(const Cor *c);

int main(void){

    int r, g, b;
    Cor cor;

    printf("Vermelho: ");
    scanf("%d", &r);
    printf("Verde: ");
    scanf("%d", &g);
    printf("Azul: ");
    scanf("%d", &b);

    cor = novaCor(r, g, b);

    printf("Cor base:");
    imprimirCor(&cor);

    Cor clareada = clarear(&cor);

    printf("Cor clareada:");
    imprimirCor(&clareada);

    return 0;
}

Cor novaCor(int vermelho, int verde, int azul){
    Cor nc;
    nc.vermelho = (vermelho < 0) ? 0 : (vermelho > 255) ? 255 : vermelho;
    nc.verde = (verde < 0) ? 0 : (verde > 255) ? 255 : verde;
    nc.azul = (azul < 0) ? 0 : (azul > 255) ? 255 : azul;
   
    return nc;
}

void imprimirCor(const Cor *c){
    printf(" rgb( %d, %d, %d )\n", c->vermelho, c->verde, c->azul);
}

Cor clarear(const Cor *c){
    if(c->vermelho == 0 && c->verde == 0 && c->azul == 0){
        int nr = 3;
        int ng = 3;
        int nb = 3;

        return novaCor(nr, ng, nb);
    }
    else{
        int nr = c->vermelho < 3 ? 3 : c->vermelho;
        int ng = c->verde < 3 ? 3 : c->verde;
        int nb = c->azul < 3 ? 3 : c->azul;

        nr = (int)(nr / 0.7);
        ng = (int)(ng / 0.7);
        nb = (int)(nb / 0.7);

        nr = nr > 255 ? 255 : nr;
        ng = ng > 255 ? 255 : ng;
        nb = nb > 255 ? 255 : nb;

        return novaCor(nr, ng, nb);
    }
}
