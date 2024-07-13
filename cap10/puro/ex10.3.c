#include <stdio.h>
#include <stdlib.h>

typedef struct Hora{
    int hora;
    int minuto;
    int segundo;
}Hora;

Hora gerarHora(int quantidadeSegundos);
void imprimirHora(const Hora *hora);

int main(void){

    Hora h;
    int segundos;

    printf("Segundos: ");
    scanf("%d", &segundos);

    h = gerarHora(segundos);

    imprimirHora(&h);
    printf("\n");

    return 0;
}

Hora gerarHora(int quantidadeSegundos){
    Hora h;
    h.hora = quantidadeSegundos / 3600;
    h.minuto = (quantidadeSegundos % 3600) / 60;
    h.segundo = quantidadeSegundos % 60;
    return h;
}

void imprimirHora(const Hora *hora){
    printf("Hora correspondente: %02d:%02d:%02d", hora->hora, hora->minuto, hora->segundo);
}