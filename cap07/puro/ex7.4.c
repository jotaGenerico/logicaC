#include <stdio.h>
#include <stdlib.h>

int lePositivo(int n);
int somatorio(int n);

int main(void){

    int array[5];

    for(int i = 0; i < 5; i++){
        array[i] = lePositivo(i);
    }

    for(int i = 0; i < 5; i++){
        printf("Somatorio de 1 a %d: %d\n", array[i], somatorio(array[i]));
    }

    return 0;
}

int lePositivo(int n){
    int positivo;

    printf("n[%d]: ", n);
    scanf("%d", &positivo);

    do{
        if(positivo <= 0){
            printf("Entre com um valor positivo: ");
            scanf("%d", &positivo);
        }
    }while(positivo <= 0);

    return positivo;
}

int somatorio(int n){
    int soma = 0;

    for(int i = 1; i <= n; i++){
        soma += i;
    }

    return soma;
}
