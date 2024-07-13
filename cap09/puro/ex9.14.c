#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void tornarMaiuscula(char *str);

#define T 41

int main(void){

    char frase[T];

    printf("Frase: ");
    fgets(frase, T, stdin);
    frase[strlen(frase)-1] = '\0';

    tornarMaiuscula(frase);

    printf("%s\n", frase);

    return 0;
}

void tornarMaiuscula(char *str){
    for(int i=0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }
}
