#include <stdio.h>
#include <stdlib.h>

int absoluto(int n);

int main(void){

    int array[5];

    for(int i = 0; i < 5; i++){
        printf("n0: ");
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("absoluto(%d) = %d\n", array[i], absoluto(array[i]));
    }
    
    return 0;
}

int absoluto(int n){
    return n >= 0 ? n : -n;
}