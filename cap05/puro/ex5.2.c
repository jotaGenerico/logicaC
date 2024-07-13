#include <stdio.h>
#include <stdlib.h>

int main(void){

    int array1[3][3];
    int array2[3][3];
    int array3[3][3];

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            printf("array1[%d][%d]: ", i, j);
            scanf("%d", &array1[i][j]);
        }
    }

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            printf("array2[%d][%d]: ",i ,j);
            scanf("%d", &array2[i][j]);
        }
    }

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            array3[i][j] = array1[i][j] + array2[i][j];
        }
    }

    printf("array1:       array2:       arraySoma:\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == 2){
                printf("%03d", array1[i][j]);
            }
            else{
                printf("%03d ", array1[i][j]);
            }
        }        
        if(i == 1){
            printf(" + ");
        }
        else{
            printf("   ");
        }
        for(int j = 0; j < 3; j++){
            if(j == 2){
                printf("%03d", array2[i][j]);
            }
            else{
                printf("%03d ", array2[i][j]);
            }
        }
        if(i == 1){
            printf(" = ");
        }
        else{
            printf("   ");
        }        
        for(int j = 0; j < 3; j++){
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