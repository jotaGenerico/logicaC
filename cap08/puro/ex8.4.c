#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void decompoeData(int diaDoAno, int ano, int *mes, int *dia);
bool ehBissexto(int ano);

int main(void){

    int diaDoAno, ano;
    int mes, dia;

    printf("Dia do ano: ");
    scanf("%d", &diaDoAno);

    printf("Ano: ");
    scanf("%d", &ano);

    decompoeData(diaDoAno, ano, &mes, &dia);

    printf("O dia %d do ano %d cai no dia %d do mes %d.\n", diaDoAno, ano, dia, mes);

    return 0;
}

bool ehBissexto(int ano){
    if(ano %4 == 0 && (ano % 100 != 0 || ano % 400 == 0 )){
        return true;
    }
    return false;
}

void decompoeData(int diaDoAno, int ano, int *mes, int *dia){
    int bissexto[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    int normal[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int *diasAno = ehBissexto(ano) ? bissexto : normal;
    
    for(int i=1; i < 12; i++){
        if(diaDoAno <= diasAno[i]){
                *mes = i;
                *dia = diaDoAno - diasAno[i-1];
                return;
        }
    }

    *mes = 12;
    *dia = diaDoAno - diasAno[11];
}



