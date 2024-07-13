#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void){

    int array[N];
    int arrayReversa[N];
    
    for(int i = 0; i < N; i++){
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < N; i++){
        arrayReversa[i] = array[N - 1 - i];
    }

    for(int i = 0; i < N; i++){
        printf("arrayInv[%d] = %d\n", i, arrayReversa[i]);
    }

    return 0;

}