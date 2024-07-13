#include <stdio.h>
#include <stdlib.h>

float maiorNumero(float n1, float n2);

int main(void){

    float array1[5];
    float array2[5];
    float valor;

    for(int i = 0; i < 5; i++){ 
        for(int j = 1; j <= 2; j++){
            do{
                printf("n%d[%d]: ", j, i);
                scanf("%f", &valor);

                if(valor <= 0){
                    printf("Entre com um valor positivo!\n");
                }
            }while(valor <= 0);

            if(j == 1){
                array1[i] = valor;
            }
            else{
                array2[i] = valor;
            }
        }
    }

    for(int i = 0; i < 5; i++){
        float resultado = maiorNumero(array1[i], array2[i]);

        if(resultado == 1){
            printf("%.2f, %.2f: Eles sao iguais\n", array1[i], array2[i]);
        }
        else{
            printf("%.2f, %.2f: O maior valor e %.2f\n", array1[i], array2[i], resultado);
        }
    }
   
    return 0;
}

float maiorNumero(float n1, float n2){
    if(n1 > n2){
        return n1;
    }
    else if(n2 > n1){
        return n2;
    }
    else{
        return 1;
    }
}
