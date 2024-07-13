#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanho(const char *str);

#define T 41

int main(void){

    char frase[T];

    printf("Frase: ");
    fgets(frase, T, stdin);
    frase[strcspn(frase, "\n")] = '\0';
    
        
    printf("%d caractere(s)!\n", tamanho(frase));

    return 0;
}

int tamanho(const char *str){
    int tamanho = strcspn(str, "\0");
    return tamanho;
}