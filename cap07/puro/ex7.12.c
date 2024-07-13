#include <stdio.h>
#include <stdlib.h>

void classificaDupla(int n1, int n2);

int main(void){
    int array[3][2];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("n%d[%d]: ", j+1, i);
            scanf("%d", &array[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        printf("%d e %d: ", array[i][0], array[i][1]);
        classificaDupla(array[i][0], array[i][1]);
    }
    return 0;
}

void classificaDupla(int n1, int n2){
    if(n1 < n2){
        printf("%d <= %d\n", n1, n2);
    }
    else{
        printf("%d <= %d\n", n2, n1);
    }
}