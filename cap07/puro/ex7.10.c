#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int calculaDigito(int n);

int main(void){

    int n;
    int verificador;

    printf("Numero: ");
    scanf("%d", &n);

    if(n <= 0 || n > 9999){
        return 0;
    }
    else{
        verificador = calculaDigito(n);
        printf("Digito verificador de %d: %d\n", n, verificador);
    }

    return 0;
}

int calculaDigito(int n){

    int soma = 0;
    int peso = 2;

    while(n > 0){
        int unidade = n % 10;
        soma += unidade * peso;
        peso++;
        n /= 10;
    }

    int resto = soma % 11;
    int digito = 11 - resto;

    if(digito == 11 || digito == 10){
        digito = 0;
    }

    return digito;
}