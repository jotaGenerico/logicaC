#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define T 41

int main(void){
    char sentenca[T];
    char novaSentenca[T];
    int index = 0;

    printf("Sentenca: ");
    fgets(sentenca, T, stdin);
    sentenca[strlen(sentenca)-1] = '\0';

    for(int i=0; i < strlen(sentenca); i++){
        if(i % 2 != 0){
            if(isblank(sentenca[i])){
                novaSentenca[index++] = '\'';
                novaSentenca[index++] = ' ';
                novaSentenca[index++] = '\'';
            }
            else{
                novaSentenca[index++] = sentenca[i];
            }
            novaSentenca[index++] = ',';
            novaSentenca[index++] = ' ';
        }
    }

    novaSentenca[strlen(novaSentenca)-2] = '\0';
    printf("%s\n", novaSentenca);

    return 0;
}
