#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define T 41

int main(void){

    char sentenca[T];
    char novaSentenca[T];
    int indice = 0;

    printf("Sentenca: ");
    fgets(sentenca, T, stdin);
    sentenca[strlen(sentenca)-1] = '\0';

    for(int i=0; i < strlen(sentenca); i++){
        if(i%2==0){            
            if(isblank(sentenca[i])){
                novaSentenca[indice++] = '\'';
                novaSentenca[indice++] = ' ';
                novaSentenca[indice++] = '\'';
            }
            else{
                novaSentenca[indice++] = sentenca[i];
            }
            novaSentenca[indice++] = ',';
            novaSentenca[indice++] = ' ';
        }
    }

    novaSentenca[strlen(novaSentenca)-2] = '\0';
    printf("%s\n", novaSentenca);

    return 0;
}
