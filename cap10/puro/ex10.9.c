#include <stdio.h>
#include <stdlib.h>

typedef struct Cor{
    int vermelho;
    int verde;
    int azul;
}Cor;

Cor novaCor(int vermelho, int verde, int azul);
void imprimirCor(const Cor *c);
Cor escurecer(const Cor *c);

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

    Cor escurecida = escurecer(&cor);

    printf("Cor escurecida:");
    imprimirCor(&escurecida);

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

Cor escurecer(const Cor *c){
    int nr = c->vermelho * 0.7;
    int ng = c->verde * 0.7;
    int nb = c->azul * 0.7;

    return novaCor(nr, ng, nb);
}
