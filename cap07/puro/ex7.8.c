#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int lePositivo(int n);
int saoAmigos(int a, int b);
int somaDivisores(int n);

#define N 5

int main(void){

    int array1[N];
    int array2[N];
    int valor;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 1; j++){
            printf("n%d[%d]: ", j + 1, i);
            scanf("%d", &valor);

            while(lePositivo(valor) == false){
                printf("Entre com um valor positivo: ");
                scanf("%d", &valor);
            }

            if(j == 0){
                array1[i] = valor;
            }
            else{
                array2[i] = valor;
            }
        }
    }

    for(int i = 0; i < N; i++){
        int a = array1[i];
        int b = array2[i];

        if(saoAmigos(a, b) == true){
            printf("%d e %d sao amigos\n", a, b);
        }
        else{
            printf("%d e %d nao sao amigos\n", a, b);
        }
    }
    return 0;
}

int lePositivo(int n){
    if(n > 0){
        return true;
    }
    return false;
}

int somaDivisores(int n){
    int soma = 0;

    for(int i = 1; i < n; i++){
        if(n % i == 0){
            soma += i;
        }
    }
    return soma;
}

int saoAmigos(int a, int b){
    if(somaDivisores(a) == b && somaDivisores(b) == a){
        return true;
    }
    return false;
}
