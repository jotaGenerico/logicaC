#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void){
    
    int array[N];
    int valido;
    int primeiro;

    printf("Quantidade de elementos (1 a 9): ");
    scanf("%d", &valido);

    if(valido > 9){
        while(valido > 9){
            printf("Quantidade incorreta, forneca novamente!\n");
            printf("Quantidade de elementos (1 a 9): ");
            scanf("%d", &valido);
        }
    }
    
    for(int i = 0; i < valido; i++){
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }
        
    printf("Valor que sera inserido: ");
    scanf("%d", &primeiro);

    for(int i = valido; i > 0; i--){
        array[i] = array[i - 1];
    }

    array[0] = primeiro;

    for(int i = 0; i < valido + 1; i++){
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;

}