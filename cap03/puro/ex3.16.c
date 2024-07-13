#include <stdio.h>
#include <stdlib.h>

int main(void){

    int fibonacci;
    int t1 = 1;
    int t2 = 1;

    for(int i = 1; i <= 20; i++){
        printf( "%d ", t1 );
        fibonacci = t1 + t2;
        t1 = t2;
        t2 = fibonacci;

    }

    return 0;

}