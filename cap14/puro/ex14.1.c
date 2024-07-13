#include <stdio.h>
#include <stdlib.h>

int ackermann( int m, int n);

int main(void){

    int m;
    int n;
    int acker;

    printf("Entre com o valor de m: ");
    scanf("%d", &m);

    printf("Entre com o valor de n: ");
    scanf("%d", &n);

    acker = ackermann( m, n);

    printf("ackermann( %d, %d ) = %d\n", m, n, acker);


    return 0;
}

int ackermann( int m, int n){
    
    if(m == 0){
        return n + 1;
    }
    else if(n == 0){
        return ackermann(m-1, 1);
    }
    else{
        return ackermann(m-1, ackermann(m, n-1));
    }

    return 0;
}