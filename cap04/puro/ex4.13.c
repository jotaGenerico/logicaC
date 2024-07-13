#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void){

    int array[N];
    int posicao;

    for(int i = 0; i < N; i++){
        printf("array[%d]: ",i);
        scanf("%d", &array[i]);
    }

    printf("Posicao a ser removida (0 a 9): ");
    scanf("%d", &posicao);

    if(posicao > 9){
        while(posicao > 9){
            printf("Posicao invalida, forneca novamente!\n");
            printf("Posicao a ser removida (0 a 9): ");
            scanf("%d", &posicao);
        }
    }

    for(int i = posicao; i < N; i++){
        array[i] = array[i + 1];
    }
    
    for(int i = 0; i < N - 1; i++){
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;

}