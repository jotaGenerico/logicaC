#include <stdio.h>
#include <stdlib.h>

int main(void){
    float notas[10];
    float soma = 0.0;
    float media;

    printf("Forneca a nota de 10 alunos: \n");
        
    for(int i = 0; i < 10; i++){
        printf("Nota %02d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    media = soma / 10.0;
    
    printf("A media aritmetica das dez notas e: %.2f\n", media);

    return 0;
}
