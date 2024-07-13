#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool ehPalindromo(const char *str);

#define T 41

int main(void){

    char string[T];
    bool palindromo;

    printf("Frase: ");
    fgets(string, T, stdin);
    string[strlen(string)-1] = '\0';

    palindromo = ehPalindromo(string);

    if(palindromo){
        printf("\"%s\" eh um palindromo!\n", string);
    }
    else{
        printf("\"%s\" nao eh um palindromo!\n", string);
    }

    return 0;
}

bool ehPalindromo(const char *str){
    int interador = strlen(str);
    int negativo = interador - 1;

    for(int i = 0; i < interador / 2; i++){
        if(str[i] != str[negativo--]){
            return false;
        }
    }
    return true;
}
