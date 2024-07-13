#include <stdio.h>
#include <stdlib.h>

void classificaTrinca(int n1, int n2, int n3);

#define N 3

int main(void){
    int array[N][N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("n%d[%d]: ", i + 1, j);
            scanf("%d", &array[i][j]);
        }
    }

    for(int i = 0; i < N; i++){
        printf("%d, %d e %d: ", array[i][0], array[i][1], array[i][2]);
        classificaTrinca(array[i][0], array[i][1], array[i][2]);
    }

    return 0;
}

void classificaTrinca(int n1, int n2, int n3){
    if(n1 < n2 && n1 < n3){
        if(n2 < n3){
            printf("%d <= %d <= %d\n", n1, n2, n3);            
        }
        else{
            printf("%d <= %d <= %d\n", n1, n3, n2);
        }
    }
    else if(n2 < n1 && n2 < n3){
        if(n1 < n3){
            printf("%d <= %d <= %d\n", n2, n1, n3);
        }
        else{
            printf("%d <= %d <= %d\n", n2, n3, n1);
        }
    }
    else{
        if(n1 < n2){
            printf("%d <= %d <= %d\n", n3, n1, n2);
        }
        else{
            printf("%d <= %d <= %d\n", n3, n2, n1);
        }
    }
}