#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int contarPalavras(const char *str);

#define T 41

int main(void){

    char frase[T];
    int quantidade;

    printf("Frase: ");
    fgets(frase, T, stdin);
    frase[strcspn(frase, "\n")] = '\0';

    quantidade = contarPalavras(frase);

    printf("Quantidade de palavras: %d\n", quantidade);

    return 0;
}

int contarPalavras(const char *str){
    int contador = 1;
    
    for(int i=0; i < strlen(str); i++){
        if(isblank(str[i])){
            contador++;
        }
    }
    return contador;
}