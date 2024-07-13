#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Data{
    int dia;
    int mes;
    int ano;
}Data;

int diaDoAno(const Data *data);

int main(void){

    Data d;
    int dia;

    printf("dia: ");
    scanf("%d", &d.dia);
    printf("mes: ");
    scanf("%d", &d.mes);
    printf("ano: ");
    scanf("%d", &d.ano);

    dia = diaDoAno(&d);

    printf("O dia do ano da data %02d/%02d/%04d eh %d.\n", d.dia, d.mes, d.ano, dia);

    return 0;
}

int diaDoAno(const Data *data){

    int bissexto[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    int normal[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    bool ano;
    int dias;

    if(data->ano %4 == 0 && (data->ano % 100 != 0 || data->ano % 400 == 0 )){
        ano = true;
    }

    if(ano){
        dias=bissexto[data->mes-1];
    }
    else{
        dias=normal[data->mes-1];        
    }
    
    return dias + data->dia;
}