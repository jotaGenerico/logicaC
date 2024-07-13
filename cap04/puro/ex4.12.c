#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void){

    int array[N];

    for(int i = 0; i < N; i++){
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < N; i++){
        array[i] = array[i + 1];
    }

    for(int i = 0; i < N -1; i++){
        printf("array[%d] = %d\n", i, array[i] );
    }

    return 0;

}