#include <stdio.h>
#include <stdlib.h>

int main(void){

    for(int i = 1; i <= 5; i++){

        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }

    for(int i = 1; i <= 4; i++){

        for(int j = i; j <= 4; j++){
            printf("*");
        }

        printf("\n");
    }

    return 0;

}