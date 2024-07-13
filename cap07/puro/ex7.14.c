#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimeDuplaClassificada(int n1, int n2, bool emOrdemCrescente);

int main(void){

    int array[5][2];
    bool emOrdemCrescente;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 2; j++){
            printf("n%d[%d]: ", j+1, i);
            scanf("%d", &array[i][j]);
        }
    }

    for(int i=0; i<5; i++){
        if(i % 2 == 0){
            emOrdemCrescente = true;
        }
        else{
            emOrdemCrescente = false;
        }
        
        printf("%d e %d: ", array[i][0], array[i][1]);
        imprimeDuplaClassificada(array[i][0], array[i][1], emOrdemCrescente);
    }
    return 0;
}

void imprimeDuplaClassificada(int n1, int n2, bool emOrdemCrescente){
    if(emOrdemCrescente){
        if(n1 < n2){
            printf("%d <= %d\n", n1, n2);
        }
        else{
            printf("%d <= %d\n", n2, n1);
        }
    }
    else{
        if(n1 > n2){
            printf("%d >= %d\n", n1, n2);
        }
        else{
            printf("%d >= %d\n", n2, n1);
        }
    }
}