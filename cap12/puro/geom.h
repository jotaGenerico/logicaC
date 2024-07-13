#ifndef GEOM_H_INCLUDED
#define GEOM_H_INCLUDED

//#pragma once

typedef enum TipoForma{
    RETANGULO,
    CIRCULO
}TipoForma;

typedef struct Ponto{

    int x;
    int y;
}Ponto;

typedef struct Forma{

    TipoForma tipo;
    Ponto centro;

    union{
        struct{
            int altura;
            int largura;
        }retangulo;
        struct{
            int raio;
        }circulo;
    }geom;
}Forma;

int calcularArea(const Forma *f);
void mover(Forma *f, int x, int y);
Forma redimensionar(const Forma *f, float fator);
void imprimirForma(const Forma *f);

#endif