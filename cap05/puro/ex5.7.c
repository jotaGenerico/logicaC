#include <stdio.h>
#include <stdlib.h>

int main(void){

    int array1[3][2];
    int array2[2][3];
    int array3[3][3]={0};

    for(int i=0; i < 3; i++){
        for(int j=0; j < 2; j++){
            printf("array1[%d][%d]: ", i, j);
            scanf("%d", &array1[i][j]);
        }
    }

    for(int i=0; i < 2; i++){
        for(int j=0; j < 3; j++){
            printf("array2[%d][%d]: ",i ,j);
            scanf("%d", &array2[i][j]);
        }
    }

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            for(int k=0; k < 2; k++){
                array3[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }

    printf("A x B =\n");
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            if(j == 2){
                printf("%03d", array3[i][j]);
            }
            else{
                printf("%03d ", array3[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}