#include <stdio.h>
#include <stdlib.h>

int main(void){

    int array1[2][3];
    int array2[3][2];

    for(int i=0; i < 2; i++){
        for(int j=0; j < 3; j++){
            printf("array[%d][%d]: ",i ,j);
            scanf("%d", &array1[i][j]);
        }
    }

    for(int i=0; i < 2; i++){
        for(int j=0; j < 3; j++){
            array2[j][i] = array1[i][j];
        }
    }

    printf("\nM:\n");
    for(int i=0; i < 2; i++){
        for(int j=0; j < 3; j++){
            if(j == 2){
                printf("%03d", array1[i][j]);
            }
            else{
                printf("%03d ", array1[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nMt:\n");
    for(int i=0; i < 3; i++){
        for(int j=0; j < 2; j++){
            if(j == 1){
                printf("%03d", array2[i][j]);
            }
            else{
                printf("%03d ", array2[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}