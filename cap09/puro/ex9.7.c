#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 5
#define C 2
#define T 41

int main(void){

    char nomes[L][C][T];
    
    for(int i=0; i < L; i++){
        for(int j=0; j < C; j++){
            printf("Par %d, palavra %d: ", i + 1, j + 1);
            fgets(nomes[i][j], T, stdin);            
            nomes[i][j][strcspn(nomes[i][j], "\n")] = '\0';
        }
    }

    for(int i=0; i < L; i++){
        int ordem = strcmp(nomes[i][0], nomes[i][1]);

        if(ordem < 0){
                printf("%s - %s: ORDEM CRESCENTE\n", nomes[i][0], nomes[i][1]);
        }
        else if(ordem > 0){
                printf("%s - %s: ORDEM DECRESCENTE\n", nomes[i][0], nomes[i][1]);
        }
        else{
            printf("%s - %s: IGUAIS\n", nomes[i][0], nomes[i][1]);
        }
    }

    return 0;
}