#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void contarOcorrencias(const char *str, int *a, int *b, int *c, int *d, int *e);

#define T 41

int main(void){

    char frase[T];
    
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;

    printf("Frase: ");
    fgets(frase, T, stdin);
    frase[strlen(frase)-1] = '\0';

    contarOcorrencias(frase, &a, &b, &c, &d, &e);

    printf("A/a: %d\n"
           "B/b: %d\n"
           "C/c: %d\n"
           "D/d: %d\n"
           "E/e: %d\n", a, b, c, d, e);


    return 0;
}

void contarOcorrencias(const char *str, int *a, int *b, int *c, int *d, int *e){

    for(int i=0; i < strlen(str); i++){
        if('a' == str[i] || 'A' == str[i]){
            (*a)++;
        }
        else if('b' == str[i] || 'B' == str[i]){
            (*b)++;
        }
        else if('c' == str[i] || 'C' == str[i]){
            (*c)++;
        }
        else if('d' == str[i] || 'D' == str[i]){
            (*d)++;
        }
        else if('e' == str[i] || 'E' == str[i]){
            (*e)++;
        }
    }
}