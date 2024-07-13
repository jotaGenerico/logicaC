/* nao fui capaz de estabelecer essa logica
   apenas transcrevi a logica criada pelo chat gpt, 
   que foi basicamente ir preenchendo as laterais e diminuindo
   assim fez as camadas ao entorno, e finalizando o algoritimo
   mesmo ele tendo criado o algoritimo ainda demorei muito para compreender e poder 
   transcrever para a linguagem C */
#include <stdio.h>
#include <stdlib.h>

int main(void){

    int escolha;
    
    printf("Numero entre 1 e 100: ");
    scanf("%d", &escolha);

    if(escolha < 1 || escolha > 100){
        printf("Numero incorreto!");
        return 1;
    }

    int array[escolha][escolha];
    int bordas = (escolha + 1) / 2;
    
    for(int borda = 0; borda < bordas; borda++){
        int valor = borda + 1;
        for(int i = borda; i < escolha - borda; i++){
            for(int j = borda; j < escolha - borda; j++){
                array[i][j] = valor;
            }
        }
    }
    
    for (int i = 0; i < escolha; i++) {
        for (int j = 0; j < escolha; j++) {
            printf("%3d", array[i][j]);
            if(j < escolha - 1){
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}