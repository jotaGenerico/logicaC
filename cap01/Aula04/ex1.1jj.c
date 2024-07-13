#include <stdio.h>
#include <stdlib.h>

int main(void){

    int idade = 45;       // variavel inteira
    char letra = 'J';      // variavel caracter
    float altura = 1.75;    // variavel ponto flutuante

    
    int paresDeTenis = 5; 
    char letraInicial = 'd'; // aspas simples soh funcionam para 1 caracter ou escape
    float peso = 90.5; 

    /*outra forma de comentar com mais de uma linha
      
      a funcao printf eh capaz de interpolar dados dentro do texto
      marcando posicoes para string de saida usando % como python 2

      formatos
      %i inteiro (nao usual)
      %d digito/inteiro (boa pratica)
      %c caracter (letras)
      %f float (ponto flutuante)

      opcoes de formatacao das casas decimais em floats
      %.nf n sendo a quantidade de casas decimais
      %.2f saida 1,99
      %.4f saida 3.1415
      */

     float pi = 3.1415; 
     float raio = 20.78; 
     float circunferencia = 2 * pi * raio; 
     float area = pi * raio * raio; 

     printf("o circulo de raio %f tem: \n", raio);            //testando formatacoes
     printf("\tcircunferencia = %.2f\n", circunferencia); 
     printf("area eh %.2f * %.2f * %.2f\n", pi, raio, raio); 
     printf("\tarea = %.2f\n", area); 


    return 0; 
}
