/*codigo refatorado pelo chat gpt, eu consegui compreender o codigo de maneira geral
  mas ainda nao entendi pq o *a ja era um ponteiro entao nao precisava fornecer o endereço &a da array
  tambem nao entendi de onde ele tirou q o int n era na verdade o tamanho da array, e tambem nao ficou
  claro pq ele usou a chave para retornar a resposta -1 caso o indice nao fosse encontrado.
  no meu codigo eu rodei a funçao buscar(&a, numero buscado, chave apenas declarada como inteiro
  ela receberia dentro da funçao -1 ou o indice, oq me faria imprimir as mensagens de saida
*/


#include <stdio.h>
#include <stdlib.h>

int buscar(const int *a, int n, int chave);

#define N 10

int main(void){
    int a[N];
    int chave;
    int n;

    for(int i=0; i < N; i++){
        printf("n[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("Buscar por: ");
    scanf("%d", &n);

    chave = buscar(a, N, n);

    if(chave != -1){
        printf("O valor %d foi encontrado na posicao %d.\n", n, chave);
    }
    else{
        printf("O valor %d nao foi encontrado.\n", n);
    }

    return 0;
}

// Função de busca
int buscar(const int *a, int n, int chave){
    for(int i = 0; i < n; i++){
        if(a[i] == chave){
            return i; // Retorna a posição onde encontrou
        }
    }
    return -1; // Retorna -1 se não encontrou
}
