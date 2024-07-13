#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void) {
    int linhas1;
    int colunas1;
    int linhas2;
    int colunas2;

    int array1[N][N];
    int array2[N][N];
    int array3[N][N] = {0};

    printf("escolha a dimensao do array( 1x1 - 10x10)\n");
    
    printf("array1 (linhas): ");
    scanf("%d", &linhas1);
    printf("array1 (colunas): ");
    scanf("%d", &colunas1);

    if(linhas1 < 1 || linhas1 > N || colunas1 < 1 || colunas1 > N){
        printf("1x1 minimo, 10x10 maximo.");
        return 1;
    }

    printf("array2 (linhas): ");
    scanf("%d", &linhas2);
    printf("array2 (colunas): ");
    scanf("%d", &colunas2);

    if(linhas2 < 1 || linhas2 > N || colunas2 < 1 || colunas2 > N){
        printf("1x1 minimo, 10x10 maximo.");
        return 1;
    }

    if(colunas1 != linhas2){
        printf("arrays nao compatveis para multiplicacao.\n");
        printf("linhas da 1 devem ser iguais as colunas da 2\n");
        return 1;
    }
    
    printf("elementos do array1:\n");
    for(int i=0; i < linhas1; i++){
        for(int j=0; j < colunas1; j++){
            printf("array1[%d][%d]: ",i ,j);
            scanf("%d", &array1[i][j]);
        }
    }

    printf("elementos do array2:\n");
    for(int i=0; i < linhas2; i++){
        for(int j=0; j < colunas2; j++){
            printf("array2[%d][%d]: ",i ,j);
            scanf("%d", &array2[i][j]);
        }
    }

    for(int i=0; i < linhas1; i++){
        for(int j=0; j < colunas2; j++){
            for(int k=0; k < colunas1; k++){
                array3[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }

    printf("arrayMulti:\n");
    for(int i=0; i < linhas1; i++){
        for(int j=0; j < colunas2; j++){
            printf("%03d ", array3[i][j]);
        }
        printf("\n");
    }
    return 0;

}
