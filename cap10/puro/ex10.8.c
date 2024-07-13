#include <stdio.h>
#include <stdlib.h>

typedef struct Cor{
    int vermelho;
    int verde;
    int azul;
}Cor;

Cor novaCor(int vermelho, int verde, int azul);
void imprimirCor(const Cor *c);

void setVermelho(Cor *c, int vermelho);
void setVerde(Cor *c, int verde);
void setAzul(Cor *c, int azul);

int main(void){

    int r, g, b;
    int rn, gn, bn;
    Cor cor;

    printf("Vermelho: ");
    scanf("%d", &r);
    printf("Verde: ");
    scanf("%d", &g);
    printf("Azul: ");
    scanf("%d", &b);

    printf("Novo vermelho: ");
    scanf("%d", &rn);
    printf("Novo verde: ");
    scanf("%d", &gn);
    printf("Novo azul: ");
    scanf("%d", &bn);

    cor = novaCor(r, g, b);

    printf("Cor:");
    imprimirCor(&cor);
    setVermelho(&cor, rn);
    setVerde(&cor, gn);
    setAzul(&cor, bn);
    printf("Cor alterada:");
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
    printf(" rgb( %d, %d, %d )\n", c->vermelho, c->verde, c->azul);
}

void setVermelho(Cor *c, int vermelho){
    if(vermelho <= 0){
        c->vermelho = 0;
    }
    else if(vermelho >= 255){
        c->vermelho = 255;
    }
    else{
        c->vermelho = vermelho;
    }
}

void setVerde(Cor *c, int verde){
    if(verde <= 0){
        c->verde = 0;
    }
    else if(verde >= 255){
        c->verde = 255;
    }
    else{
        c->verde = verde;
    }
}

void setAzul(Cor *c, int azul){
    if(azul <= 0){
        c->azul = 0;
    }
    else if(azul >= 255){
        c->azul = 255;
    }
    else{
        c->azul = azul;
    }
}