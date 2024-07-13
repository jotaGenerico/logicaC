#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 41

int main(void){

    char texto[T];

    printf("String: ");
    fgets(texto, T, stdin);
    texto[strlen(texto)-1] = '\0';

    for(int i=0; i < 4; i++){
        printf("%c", texto[i]);
        if(i < 3){
            printf(", ");
        }
        else{
            printf(".\n");
        }
    }

    return 0;
}