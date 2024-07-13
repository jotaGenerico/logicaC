#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

int ehPar(int n);
int ehDivisivel(int dividendo, int divisor);

int main(void){

    int array[N][2];
    int primeiro;
    int segundo;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 1; j++){
            printf("n%d[%d]: ", j + 1, i);
            scanf("%d", &array[i][j]);
        }
    }

    for(int i =0; i < N; i++){
        for(int j = 0; j < 1; j++){
            primeiro = array[i][j];
            segundo = array[i][j+1];
            if(ehPar(primeiro) == true){
                printf("%d eh par e %d ", primeiro, primeiro);
            }
            else{
                printf("%d eh impar e %d ", primeiro, primeiro);
            }

            if(ehDivisivel(primeiro, segundo) == true){
                printf("eh divisivel por %d\n", segundo);
            }
            else{
                printf("nao eh divisivel por %d\n", segundo);
            }
        }
    }
    return 0;
}

int ehPar(int n){
    if(n % 2 == 0){
        return true;
    }
    return false;
}

int ehDivisivel(int dividendo, int divisor){
    if(dividendo % divisor == 0){
        return true;
    }
    return false;
}
