/*mais um exercicio q mal pude transcrever,
nao tenho nem ideia dq seja ou oq faz, tentei fazer como nos exercicios
mas aparentemente aquela formula soh serve para arrays 2x2*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void){
    int dimensao;
    int array[N][N];
    int determinante = 0;

    printf("dimensao do array (2x2 - 10x10):\n");
    scanf("%d", &dimensao);

    if(dimensao < 2 || dimensao > N){
        printf("Dimensao invalida.\n");
        return 1;
    }

    for(int i=0; i < dimensao; i++) {
        for(int j=0; j < dimensao; j++) {
            printf("array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    if(dimensao == 2){
        determinante = array[0][0] * array[1][1] - array[0][1] * array[1][0];
    }
    else{
        int sign = 1;
        for(int i=0; i < dimensao; i++){
            int menor[N - 1][N - 1];
            for(int j=1; j < dimensao; j++){
                for(int k=0; k < dimensao; k++){
                    if(k < i){
                        menor[j - 1][k] = array[j][k];
                    }
                    else if(k > i){
                        menor[j - 1][k - 1] = array[j][k];
                    }
                }
            }
            determinante += sign * array[0][i] * (menor, dimensao - 1);
            sign = -sign;
        }
    }

    printf("Determinante: %d\n", determinante);

    return 0;

}
