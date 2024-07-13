#include <stdio.h>
#include <stdlib.h>

int main(void){

    int array[3][2];

    for(int i=0; i < 3; i++){
        for(int j=0; j < 2; j++){
            printf("array[%d][%d]: ",i ,j);
            scanf("%d", &array[i][j]);
        }
    }

    printf("\n");

    for(int i=0; i < 3; i++){
        for(int j=0; j < 2; j++){
            if(j == 0){
                printf("%03d ", array[i][j]);
            }
            else{
                printf("%03d",array[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
        
