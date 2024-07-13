#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool numeroCorreto(int n);
int obtemDigito(int n);
int obtemNumero(int n);
int calculaDigito(int n);


int main(void){
    int n;

    printf("Numero: ");
    scanf("%d", &n);

    if( n < 10 || n > 99999){
        return 0;
    }

    printf("\nNumero completo: %d\n", n);
    printf("Numero: %d\n", obtemNumero(n));
    printf("Digito: %d\n", obtemDigito(n));
    printf("Digito calculado: %d\n", calculaDigito(obtemNumero(n)));

    if(numeroCorreto(n)){
        printf("O numero fornecido esta correto!\n");
    }
    else{
        printf("O numero fornecido esta incorreto!\n");
    }
    return 0;
}

bool numeroCorreto(int n){
    int digito = obtemDigito(n);
    int numero = obtemNumero(n);
    if(calculaDigito(numero) == digito){
        return true;
    }
    return false;
}

int obtemDigito(int n){
    int digito = n % 10;
    return digito;
}

int obtemNumero(int n){
    int numero =  n / 10;
    return numero;
}

int calculaDigito(int n){
    int peso = 2;
    int soma = 0;

    while(n > 0){
        int unidade = n % 10;
        soma += peso * unidade;
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
