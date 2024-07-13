#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void imprimirCaixa(const char *str);

#define T 41

int main(void){
    char string[T];

    printf("Digite uma string: ");
    fgets(string, T, stdin);
    string[strcspn(string, "\n")] = '\0';

    printf("\n");
    imprimirCaixa(string);

    return 0;
}

void imprimirCaixa(const char *str){
    int comprimento = strlen(str);
    
    // superior
    printf("++");
    for(int i = 0; i < comprimento + 2; i++){
        printf("=");
    }
    printf("++");
    printf("\n");

    // string
    printf("|");
    printf("|");
    printf(" ");
    printf("%s", str);
    printf(" ");
    printf("|");
    printf("|");
    printf("\n");

    // inferior
    printf("++");
    for (int i = 0; i < comprimento + 2; i++) {
        printf("=");
    }
    printf("++");
    printf("\n");
}
