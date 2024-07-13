#include <stdio.h>
#include <stdlib.h>

int main(void){

    int escolha;

    printf("Numero entre 1 e 100: ");
    scanf("%d", &escolha);

    if(escolha < 1 || escolha > 100){
        printf("Numero incorreto!");
        return 1;
    }

    for(int i = 0; i < escolha; i++){
        for(int j = 0; j < escolha; j++){
            int valor = i > j ? i - j : j - i;
            printf("%3d", valor + 1);
        }
        printf("\n");
    }

    return 0;
}