#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto{

    int x;
    int y;
}Ponto;

typedef struct Retangulo{

    Ponto s;
    Ponto i;
}Retangulo;

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir);
void imprimirRetangulo(const Retangulo *r);
Ponto obterCentro(const Retangulo *r);

int main(void){

    Retangulo caixa;
    Ponto pontoCentral, superior, inferior;

    printf("Ponto superior esquerdo\n");
    printf("    x: ");
    // testando scanf("%d", &superior.x);
    scanf("%d", &caixa.s.x);
    printf("    y: ");
    // testando scanf("%d", &superior.y);
    scanf("%d", &caixa.s.y);

    printf("Ponto inferior direito\n");
    printf("    x: ");
    // testando scanf("%d", &superior.x);
    scanf("%d", &caixa.i.x);
    printf("    y: ");
    // testando scanf("%d", &superior.x);
    scanf("%d", &caixa.i.y);

    // testando caixa = novoRetangulo(&superior, &inferior);
    pontoCentral = obterCentro(&caixa);

    imprimirRetangulo(&caixa);
    printf("Centro: (%+02d, %+02d)\n", pontoCentral.x, pontoCentral.y);

    return 0;
}

/* testando
Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir){

    Ponto superior;
    Ponto inferior;
}
*/

void imprimirRetangulo( const Retangulo *r ){
    
    printf("(%+02d, %+02d) =====|\n", r->s.x, r->s.y);
    printf("|               |\n");
    printf("|               |\n");
    printf("|===== (%+02d, %+02d)\n", r->i.x, r->i.y);
}

Ponto obterCentro(const Retangulo *r){
    Ponto pcentral;

    pcentral.x = (r->s.x + r->i.x) / 2;
    pcentral.y = (r->s.y + r->i.y) / 2;

    return pcentral;
}