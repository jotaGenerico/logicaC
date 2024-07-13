#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool contem(const char *fonte, const char *aPesquisar);

#define T 41

int main(void){

    char string[T];
    char busca[T];
    bool localizada;

    printf("String fonte: ");
    fgets(string, T, stdin);
    string[strcspn(string, "\n")] = '\0';

    printf("String a pesquisar: ");
    fgets(busca, T, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    localizada = contem(string, busca);

    if(localizada){
        printf("\"%s\" esta contida em \"%s\"\n", busca, string);
    }
    else{
        printf("\"%s\" nao esta contida em \"%s\"\n", busca, string);
    }

    return 0;
}

bool contem(const char *fonte, const char *aPesquisar){
    if(strstr(fonte, aPesquisar)){
        return true;
    }
    else{
        return false;
    }
}
