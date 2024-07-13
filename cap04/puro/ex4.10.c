#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void){

    int array[N];
    int arrayMaiores[N];
    int maior = 0;
    int maiores = 0;

    for(int i = 0; i < N; i++){
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("Copiar maiores que: ");
    scanf("%d", &maior);

    for(int i = 0; i < N; i++){
        if(array[i] > maior){
            arrayMaiores[maiores] = array[i];
            maiores++;
        }
    }

    if(maiores > 0){
        for(int i = 0; i < maiores; i++){
            printf("arrayCopia[%d] = %d\n", i, arrayMaiores[i]);
        }
    }
    else{
        printf("Nao houve copia!\n");
    }

    return 0;

}