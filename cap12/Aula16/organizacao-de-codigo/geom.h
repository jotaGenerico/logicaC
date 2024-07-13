/* 
 * Arquivo: organizacao-de-codigo/geom.h
 * Autor: Prof. Dr. David Buzatto
 */

/* as guardas de inclusão evitam que o mesmo
 * cabeçalho seja inserido mais de uma vez em
 * algum arquivo.
 */
#ifndef GEOM_H_INCLUDED
#define GEOM_H_INCLUDED

/* uma alternativa ao uso das guardas de inclusão
 * é a diretiva "#pragma once" que deve ser usada no
 * início do arquivo de cabeçalho, não havendo então
 * a necessidade de criar as guardas de inclusão.
 * 
 * Exemplo abaixo (comentado).
 */
//#pragma once


/* nos arquivos de cabeçalho (extensão .h),
 * usualmente, haverá as seguintes
 * entidades:
 *
 * - definição de macros;
 * - declaração (protótipos) de funções;
 * - declaração estruturas, uniões e enumerações
 * - definião de tipos.
 *
 * ou seja, o cabeçalho é usado, usualmente,
 * para declarações e não implementações.
 */

typedef struct Ponto {
    int x;
    int y;
} Ponto;

typedef struct Linha {
    Ponto ini;
    Ponto fim;
} Linha;

typedef struct Retangulo {
    Ponto canto;
    int largura;
    int altura;
} Retangulo;

typedef struct Elipse {
    Ponto canto;
    int largura;
    int altura;
} Elipse;

typedef struct Circulo {
    Ponto centro;
    int raio;
} Circulo;

void imprimirPonto( Ponto *ponto );
void imprimirLinha( Linha *linha );
void imprimirRetangulo( Retangulo *retangulo );
void imprimirElipse( Elipse *elipse );
void imprimirCirculo( Circulo *circulo );

/* caso se tenha usado a diretiva #pragma once,
 * a linha abaixo não deve existir.
 */
#endif // GEOM_H_INCLUDED
