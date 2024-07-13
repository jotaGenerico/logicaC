#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ehPrimo(int n);

int main(void){

    for(int i = 1; i <= 20; i++ ){
        if(ehPrimo(i) == true){
            printf("%d: eh primo\n", i);
        }
        else{
            printf("%d: nao eh primo\n", i);
        }
    }
    return 0;
}

int ehPrimo(int n){
    int divisores = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            divisores ++;
        }
    }

    if(divisores == 2){
        return true;
    }
    else{
        return false;
    }
}