/*
 * Arquivo: Funcoes.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Protótipos de Funções:
 *
 * O uso de protótipos é aconselhado, visto que seu objetivo
 * é informar ao compilador que essas funções estarão presentes no
 * código. Essa ação de informar é denominada "declaração da função".
 *
 * Pode-se também implementar funções diretamente, sem a declaração
 * de protótipos, entretanto, quando existe dependência entre funções,
 * há a necessidade de implementá-las em ordem, o que nem sempre é
 * possível.
 *
 * Na linguagem C não pode haver mais de uma função com o mesmo nome
 * em um mesmo escopo.
 *
 * As funções devem ser nomeadas, preferencialmente, usando o padrão
 * camel case com a primeira letra em minúscula.
 *
 * Um parâmetro de uma função é parte da função e descreve um tipo de
 * dado que será recebido. É a variável contida na declaração da função.
 *
 * Um argumento é o valor em si, passado através de um parâmetro, para a
 * função utilizar.
 */

/* protótipo da função adicao:
 *   - possui dois parâmetros inteiros => ( int, int );
 *   - retorna um inteiro => int antes do nome da função;
 *   - obs: no protótipo de uma função, não é obrigatório
 *          fornecer o nome/identificador do parâmetro.
 */
int adicao( int, int );

/* protótipo da função subtracao:
 *   - possui dois parâmetros inteiros => ( int n1, int n2 );
 *   - retorna um inteiro => int antes do nome da função;
 *   - obs: no protótipo de uma função, não é obrigatório
 *          fornecer o nome/identificador do parâmetro.
 */
int subtracao( int n1, int n2 );

/* protótipo da função pularLinha
 *   - não possui parâmetros => ( void );
 *   - não retorna nada => void antes do nome da função;
 *   - obs1: quanto uma função não possui parâmetros, usa-se a
             palavra chave void na lista de parâmetros. isso
             não é obrigatório, mas é uma boa prática, pois 
             força o compilador a verificar se a função não
             foi invocada erroneamente.
 *   - obs2: funções que não retornam valores são chamadas também
 *           de procedimentos.
 */
void pularLinha( void );

/* protótipo da função imprimirNumeros
 *   - não possui parâmetros => ();
 *   - não retorna nada => void antes do nome da função;
 *   - obs1: quanto uma função não possui parâmetros, usa-se a
             palavra chave void na lista de parâmetros. isso
             não é obrigatório, mas é uma boa prática, pois 
             força o compilador a verificar se a função não
             foi invocada erroneamente. neste exemplo foi
             deixado sem void proprositalmente.
 *   - obs2: funções que não retornam valores são chamadas também
 *           de procedimentos.
 */
void imprimirNumeros();

/* protótipo da função processarArray
 *   - possui dois parâmetros, um array de inteiros e um 
 *     inteiro => ( int a[], int n );
 *   - não retorna nada => void antes do nome da função;
 *   - obs: parâmetros que são arrays tem um comportamento "especial".
 *          Iremos aprender os detalhes disso posteriormente!
 *          Por enquanto, entenda que um array passado como parâmetro poderá
 *          ser modificado dentro da função.
 */
void processarArray( int a[], int n );

/* função imprimeTabuada
 *   - possui um parâmetro inteiro => ( int n );
 *   - não retorna nada => void antes do nome da função;
 *   - obs1: quando uma função for implementada, é obrigatória
 *           a identificação de seus parâmetros
 *   - obs2: obrigatoriamente, para funções que não possuem
 *           protótipo, é necessário implementá-las antes de
 *           usá-las.
 */
void imprimeTabuada( int n ) {

    for ( int i = 0; i <= 10; i++ ) {
        printf( "%d x %d = %d\n", n, i, n*i );
    }

}


/* função main
 *   - não possui parâmetros => ( void );
 *   - retorna um inteiro => int antes do nome da função.
 */
int main( void ) {

    int n1 = 3;
    int n2 = 4;
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int resultado;

    printf( "%d + %d = %d", n1, n2, adicao( n1, n2 ) );
    pularLinha();

    resultado = subtracao( n1, n2 );
    printf( "%d - %d = %d", n1, n2, resultado );
    pularLinha();

    printf( "zero a dez: " );
    imprimirNumeros();

    imprimeTabuada( 5 );

    printf( "Dados do array (fora da funcao):\n" );
    for ( int i = 0; i < 10; i++ ) {
        printf( "a[%d] = %d\n", i, a[i] );
    }
    processarArray( a, 10 );
    printf( "Dados do array (apos execucao da funcao):\n" );
    for ( int i = 0; i < 10; i++ ) {
        printf( "a[%d] = %d\n", i, a[i] );
    }

    return 0;

}

/*
 * implementação da função adicao
 */
int adicao( int n1, int n2 ) {
    return n1 + n2;
}

/*
 * implementação da função subtracao
 */
int subtracao( int n1, int n2 ) {

    /* variável resultado é interna à função!
     * ela tem escopo local à função.
     */
    int resultado = n1 - n2;

    return resultado;

}

/*
 * implementação da função pularLinha
 */
void pularLinha( void ) {
    printf( "\n" );
}

/*
 * implementação da função processarArray
 */
void processarArray( int a[], int n ) {

    /* cuidado, dentro da função não é possível calcular
     * o tamanho do array usando o operador sizeof.
     */

    printf( "Dados do array (dentro da funcao):\n" );
    for ( int i = 0; i < n; i++ ) {
        printf( "a[%d] = %d\n", i, a[i] );
    }

    printf( "Modificando os dados do array (dentro da funcao)...\n" );
    for ( int i = 0; i < n; i++ ) {
        a[i] += 2;
    }

    printf( "Dados do array apos modificacao (dentro da funcao):\n" );
    for ( int i = 0; i < n; i++ ) {
        printf( "a[%d] = %d\n", i, a[i] );
    }

}

/*
 * implementação da função imprimirNumeros
 */
void imprimirNumeros() {

    for ( int i = 0; i <= 10; i++ ) {
        printf( "%d ", i );
    }

    pularLinha();

}
