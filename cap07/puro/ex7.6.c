#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

int lePositivo(int n);
int somaDivisores(int n);

#define N 5

int main(void){
    int array[N];
    int valor = 0;

    for(int i = 0; i < N; i++){
        printf("n[%d]: ", i);
        scanf("%d", &valor);
        
        do{
            if(lePositivo(valor) == false){
                printf("Entre com um valor positivo: ");
                scanf("%d", &valor);
            }
        }while(lePositivo(valor) == false);

        array[i] = valor;
    }

    for(int i = 0; i < N; i++){
        int soma = somaDivisores(array[i]);
        printf("Soma dos divisores de %d: %d\n", array[i], soma);
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

    for(int i = 1; i <= n / 2; i++){
        if(n % i == 0){
            soma += i;
        }
    }
    return soma;
}

