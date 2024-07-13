#include <stdio.h>
#include <stdlib.h>

int main(void){
    int array[3][4];
    int multiplos[3][4];
    int multiplo;

    for(int i=0; i < 3; i++){
        for(int j=0; j < 4; j++){
            printf("array[%d][%d]: ",i ,j);
            scanf("%d", &array[i][j]);
        }
    }

    printf("Multiplicar por: ");
    scanf("%d", &multiplo);

    for(int i=0; i < 3; i++){
        for(int j=0; j < 4; j++){
            multiplos[i][j] = multiplo * array[i][j];
        }
    }

    printf("arrayMult:\n");

    for(int i=0; i < 3; i++){
        for(int j=0; j < 4; j++){
            if(j == 3){
                printf("%03d", multiplos[i][j]);
            }
            else{
                printf("%03d ", multiplos[i][j]);
            }
            
            
        }
        printf("\n");
    }

    return 0;
}