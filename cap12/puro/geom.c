#include <stdio.h>
#include <stdlib.h>
#include "geom.h"

int calcularArea(const Forma *f){
    if(f->tipo == RETANGULO){

        return f->geom.retangulo.altura * f->geom.retangulo.largura;
    }
    else if(f->tipo == CIRCULO){

        return 3.14159 * f->geom.circulo.raio * f->geom.circulo.raio;
    }

    return 0;
}

void mover(Forma *f, int x, int y){

    f->centro.x += x;
    f->centro.y += y;
}

Forma redimensionar(const Forma *f, float fator){

    Forma novaForma = *f;

    if(f->tipo == RETANGULO){

        novaForma.geom.retangulo.largura = (int)(f->geom.retangulo.largura * fator);
        novaForma.geom.retangulo.altura = (int)(f->geom.retangulo.altura * fator);

        novaForma.centro.x += (novaForma.geom.retangulo.largura - f->geom.retangulo.largura) / 2;
        novaForma.centro.y += (novaForma.geom.retangulo.altura - f->geom.retangulo.altura) / 2;
    }
    else if(f->tipo == CIRCULO){

        novaForma.geom.circulo.raio = (int)(f->geom.circulo.raio * fator);

        int deltaRaio = novaForma.geom.circulo.raio - f->geom.circulo.raio;
        novaForma.centro.x += deltaRaio;
        novaForma.centro.y += deltaRaio;
    }

    return novaForma;
}

void imprimirForma(const Forma *f){

    if(f->tipo == RETANGULO){
        
        printf("===== Retangulo ======\n");
        printf("| Centro: (%+03d, %+03d) |\n", f->centro.x, f->centro.y);
        printf("| Largura: %02d        |\n", f->geom.retangulo.largura);
        printf("| Altura: %02d         |\n", f->geom.retangulo.altura);
        printf("======================\n");
        printf("  Area: %d\n", calcularArea(f));
        printf("======================\n");
    }
    else if(f->tipo == CIRCULO){

        printf("====== Circulo =======\n");
        printf("| Centro: (%+03d, %+03d) |\n", f->centro.x, f->centro.y);
        printf("| Raio: %02d           |\n", f->geom.circulo.raio);
        printf("======================\n");
        printf("  Area: %02d\n", calcularArea(f));
        printf("======================\n");
    }
}