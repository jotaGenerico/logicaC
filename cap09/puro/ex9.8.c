#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 41

int main(void){

    char strings[1][3][T];
    
    for(int i=0; i < 3; i++){
        printf("String %d: ", i+1);
        fgets(strings[0][i], T, stdin);
        strings[0][i][strcspn(strings[0][i], "\n")] = '\0';
    }

    char *n1 = strings[0][0];
    char *n2 = strings[0][1];
    char *n3 = strings[0][2];

    int n12 = strcmp(n1, n2);
    int n13 = strcmp(n1, n3);
    int n23 = strcmp(n2, n3);

    if (n12 < 0 && n13 < 0) {
        if(n23 < 0){
            printf("%s, %s e %s\n", n1, n2, n3);
        }
        else{
            printf("%s, %s e %s\n", n1, n3, n2);
        }
    }
    else if(n12 > 0 && n23 < 0){
        if(n13 < 0){
            printf("%s, %s e %s\n", n2, n1, n3);
        }
        else{
            printf("%s, %s e %s\n", n2, n3, n1);
        }
    }
    else{
        if(n12 < 0){
            printf("%s, %s e %s\n", n3, n1, n2);
        }
        else{
            printf("%s, %s e %s\n", n3, n2, n1);
        }
    }

    return 0;
}