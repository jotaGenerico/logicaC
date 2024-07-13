#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b);

int main(void){

    int a;
    int b;
    int multiplo;

    printf("Entre com o valor de a: ");
    scanf("%d", &a);

    printf("Entre com o valor de b: ");
    scanf("%d", &b);

    multiplo = mdc(a, b);

    printf("mdc( %d, %d ) = %d\n", a, b, multiplo);

    return 0;
}

int mdc(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return mdc(b, a % b);
    }
}