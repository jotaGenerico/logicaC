#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a;

    printf("Altura: ");
    scanf("%d", &a);

    if(a > 0){

        for(int i = 1; i <= a; i++ ){
            for(int j = i; j < a; j++){
                printf(" ");
            }
            for(int k = 1; k <= 2 * i - 1; k++){
                printf("*");
            }
            printf("\n");
        }

    }else{

         for (int i = a; i <= -1; i++) {
            for (int j = a; j < i; j++) {
                printf(" ");
            }
            
            for (int k = 1; k <= -2 * i - 1; k++) {
                printf("*");

            }

         printf("\n");

        }
    }
    return 0;

}