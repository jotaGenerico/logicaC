/* 
 * Arquivo: EntradaSaidaPadraoFormatadosDeclaracaoVariaveis.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

int main( void ) {
    
    /* cada variável precisa de um tipo e de um identificador (nome)
     *
     * os tipos que serão usados por enquanto são:
     *    int: número inteiro
     *    char: caractere
     *    float: número decimal/ponto flutuante
     */
     
    int idade;                // variável inteira chamada idade
    char letra;               // variável para caracteres chamada letra
    float altura;             // variável decimal chamada altura
    
    int paresDeTenis = 5;     // variável inteira chamada paresDeTenis
                              // inicializada com o valor 5
                              
    char letraInicial = 'D';  // variável para caracteres chamada 
                              // letraInicial inicializada com o 
                              // valor 'D'
                              
    float peso = 90.5;        // variável decimal chamada peso
                              // inicializada com o valor 90.5 
                              // atenção: use . (ponto) como separador
                              // decimal!
    
    return 0;
    
}