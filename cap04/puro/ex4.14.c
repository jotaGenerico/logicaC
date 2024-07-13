#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void){

    int array[N];
    int impar = 0;

    for(int i = 0; i < N; i++ ){
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    for(int i =0; i < N; i++){
        if(array[i] % 2 != 0){
            array[impar] = array[i];
            impar++;
        }
    }

    for(int i = 0; i < impar; i++){
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;

}