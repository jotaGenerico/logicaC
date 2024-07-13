/* codigo corrigido pelo gpt
 * atençao para %c um unico caracter
 * e %s para uma string de caracter
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){

    char nome[100];  // para armazenar uma string
    int idade; 
    float altura; 

    printf("nome: "); 
    scanf("%99s", nome);  // para ler uma string com segurança

    printf("idade: ");      
    scanf("%d", &idade);  // leitura correta de um inteiro

    printf("altura: ");     
    scanf("%f", &altura);  // leitura correta de um float

    printf("nome: %s\nidade: %d\naltura: %f\n", nome, idade, altura); 
    printf("so far so good\n"); 

    return 0; 
}
