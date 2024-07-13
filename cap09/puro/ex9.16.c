#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void removerLetra(char *str, char c);

#define T 41

int main(void){

    char frase[T];
    char alvo;

    printf("Frase: ");
    fgets(frase, T, stdin);
    frase[strlen(frase)-1] = '\0';
    //frase[strcspn(frase, "\n")] = '\0';

    printf("Caractere: ");
    alvo = getchar();
    getchar();

    removerLetra(frase, alvo);
    printf("%s\n", frase);

    return 0;
}

void removerLetra(char *str, char c){
    int i, j = 0;

    int t = strlen(str);
    
    for (i = 0; i < t; i++) {
        if (tolower(str[i]) != tolower(c)) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
