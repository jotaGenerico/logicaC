#include <stdio.h>
#include <stdlib.h>

#define N 2

int main(void){

    int array[N][N];
    int determinante;

    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            printf("array[%d][%d]", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    determinante = array[0][0] * array[1][1] - array[0][1] * array[1][0];

    printf("Determinante: %d\n", determinante);

    return 0;
}