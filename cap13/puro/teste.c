#include <stdio.h>

int main() {
  int valor = 5; // Valor a ser usado para determinar o número de asteriscos

  for (int i = 0; i < valor; i++) { // Loop externo para controlar o número de linhas
    for (int j = 0; j < i+1 ; j++) { // Loop interno para imprimir asteriscos em cada linha
      printf("*"); // Imprime um asterisco
    }
    printf("\n"); // Quebra de linha para iniciar a próxima linha
  }

  return 0;
}
