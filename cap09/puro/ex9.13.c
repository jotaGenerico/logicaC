#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void contarOcorrencias(const char *str, int *a, int *e, int *i, int *o, int *u);

#define T 41

int main(void){

    char frase[T];

    int a, e, i, o, u = 0;
    
    printf("Frase: ");
    fgets(frase, T, stdin);
    frase[strlen(frase)-1] = '\0';

    contarOcorrencias(frase, &a, &e, &i, &o, &u);

    printf("A/a: %d\n"
           "E/e: %d\n"
           "I/i: %d\n"
           "O/o: %d\n"
           "U/u: %d\n", a, e, i, o, u);

    return 0;
}

void contarOcorrencias(const char *str, int *a, int *e, int *i, int *o, int *u){

    for(int k=0; k < strlen(str); k++){
        if(str[k] == 'a' || str[k] == 'A'){
            (*a)++;
        }
        else if(str[k] == 'e' || str[k] == 'E'){
            (*e)++;
        }
        else if(str[k] == 'i' || str[k] == 'I'){
            (*i)++;
        }
        else if(str[k] == 'o' || str[k] == 'O'){
            (*o)++;
        }
        else if(str[k] == 'u' || str[k] == 'U'){
            (*u)++;
        }
    }
}