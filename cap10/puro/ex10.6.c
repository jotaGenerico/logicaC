#include <stdio.h>
#include <stdlib.h>

typedef struct Cor{
    int vermelho;
    int verde;
    int azul;
}Cor;

Cor novaCor(int vermelho, int verde, int azul);
void imprimirCor(const Cor *c);

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

    imprimirCor(&cor);

    return 0;
}

Cor novaCor(int vermelho, int verde, int azul){
    Cor nc;
    if(vermelho <= 0){
        nc.vermelho = 0;
    }
    else if(vermelho >= 255){
        nc.vermelho = 255;
    }
    else{
        nc.vermelho = vermelho;
    }

    if(verde <= 0){
        nc.verde = 0;
    }
    else if(verde >= 255){
        nc.verde = 255;
    }
    else{
        nc.verde = verde;
    }
    
    if(azul <= 0){
        nc.azul = 0;
    }
    else if(azul >= 255){
        nc.azul = 255;
    }
    else{
        nc.azul = azul;
    }

    return nc;
}

void imprimirCor(const Cor *c){
    printf("Cor: rgb( %d, %d, %d )\n", c->vermelho, c->verde, c->azul);
}
