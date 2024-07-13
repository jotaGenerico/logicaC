#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ehTriangulo(int ladoA, int ladoB, int ladoC);
int tipoTriangulo(int ladoA, int ladoB, int ladoC);
int lePositivo(int n);

#define L 5
#define C 3

int main(void){

    int array[L][C];
    int valor;
    int a, b, c;

    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            switch(j) {
                case 0:
                    printf("ladoA[%d]: ", i);
                    break;
                case 1:
                    printf("ladoB[%d]: ", i);
                    break;
                case 2:
                    printf("ladoC[%d]: ", i);
                    break;
            }
            scanf("%d", &valor);

            while(!lePositivo(valor)) {
                printf("Entre com um valor positivo: ");
                scanf("%d", &valor);
            }
            array[i][j] = valor;
        }
    }

    for(int i = 0; i < L; i++){
        a = array[i][0];
        b = array[i][1];
        c = array[i][2];

        switch (tipoTriangulo(a, b, c)){

            case 0:
                printf("Valores %d, %d e %d: nao formam um triangulo\n", a, b, c);
                break;

            case 1:
                printf("Valores %d, %d e %d: triangulo equilatero\n", a, b, c);
                break;

            case 2:
                printf("Valores %d, %d e %d: triangulo isosceles\n", a, b, c);
                break;

            case 3:
                printf("Valores %d, %d e %d: triangulo escaleno\n", a, b, c);
                break;
        }

    }
    return 0;
}

int ehTriangulo(int ladoA, int ladoB, int ladoC){
    if(ladoA + ladoB > ladoC &&
       ladoB + ladoC > ladoA &&
       ladoC + ladoA > ladoB){
        return true;
    }
    return false;
}

int tipoTriangulo(int ladoA, int ladoB, int ladoC){
    if(ehTriangulo(ladoA, ladoB, ladoC) == true){
        if(ladoA == ladoB && ladoB == ladoC){
            return 1;
        }
        else if(ladoA == ladoB || ladoB == ladoC || ladoC == ladoA){
            return 2;
        }
        else{
            return 3;
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