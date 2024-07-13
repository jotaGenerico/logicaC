#include <stdio.h>
#include <stdlib.h>

int main(void){

    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 1; i <= 5; i++){
        for(int j = i; j <= 5; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 1; i <= 5; i++){
        for(int j = i; j < 5; j++){
            printf(" ");
        }

        for(int k = 1; k <= i; k++){
            printf("*");
        }
                
        printf("\n");   
    }
    printf("\n");

    for(int i = 1; i <= 5; i++){
        for(int j = 1; j < i; j++){
            printf(" ");
        }

        for(int k = i; k <= 5; k++){
            printf("*");
        }

        printf("\n");

    }

    return 0;
}