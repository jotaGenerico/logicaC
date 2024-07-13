#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void){

    int array1[N];
    int array2[N];
    int interseccao[N];
    int igual = 0;

    printf("Forneca os valores do primeiro array:\n");
    for(int i = 0; i < N; i++){
        printf("array1[%d]: ", i);
        scanf("%d", &array1[i]);
    }

    printf("Forneca os valores do segundo array:\n");
    for(int i = 0; i < N; i++){
        printf("array2[%d]: ", i);
        scanf("%d", &array2[i]);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(array1[i] == array2[j]){
                int inserido = 0;
                for(int k = 0; k < igual; k++){
                    if(interseccao[k] == array1[i]){
                        inserido = 1;
                        break;
                    }
                }
                if(!inserido){
                    interseccao[igual++] = array1[i];
                }
            }
        }
    }

    if(igual > 0){
        for(int i = 0; i < igual; i++){
            printf("arrayInterseccao[%d] = %d\n", i, interseccao[i]);
        }
    }
    else{
        printf("Nao ha interseccao entre os elementos dos dois arrays fornecidos!\n");
    }

    return 0;

}