#include <stdio.h>
#include <stdlib.h>

void decompoeTempo(int totalSeg, int *horas, int *minutos, int *segundos);

int main(void){

    int ts, h, m, s;

    printf("Total de segundos: ");
    scanf("%d", &ts);

    decompoeTempo(ts, &h, &m, &s);

    printf("%d segundo(s) corresponde(m) a:\n    %d hora(s)\n    %d minuto(s)\n    %d segundo(s)\n", ts, h, m, s);

    return 0;
}

void decompoeTempo(int totalSeg, int *horas, int *minutos, int *segundos){
    *horas = totalSeg / 3600;
    int restoSegundos = totalSeg % 3600;
    *minutos = restoSegundos / 60;
    *segundos = restoSegundos % 60;
}
