/*
 * Arquivo: Rand.c
 * Autor: Prof. Dr. David Buzatto
 */

/* Alguns tipos de programas, jogos por exemplo,
 * necessitam gerar valores aleatórios para que
 * alguma ação seja executada. Por exemplo, embaralhar
 * uma série de cartas, ou sortear qual a chance
 * de um ataque conectar em um oponente.
 *
 * Neste trecho de código você aprenderá a gerar
 * números pseudoaleatórios em C.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* time.h é o cabeçalho necessário para realizar a
 * semeadura do gerador de números pseudoaleatórios.
 */

/* função para gerar números aletatórios
 * dentro de um intervalo fechado.
 */
int randIntervalo( int inicio, int fim );

int main( void ) {

    /* void srand( unsigned semente )
     * int rand()
     *
     * Na linguagem C, usa-se as funções srand e rand
     * para se gerar números inteiros pseudoaletórios/
     * pseudorandômicos.
     * Ambas são definidas no cabeçalho stdlib.h.
     *
     * A função srand é usada para semear o gerador de
     * números pseudoaleatórios. Caso ela não seja
     * invocada ou seja invocada com um valor fixo,
     * a ordem dos números gerados será sempre a mesma.
     *
     * Sendo assim, tentamos simular a diferença de valor
     * de execução passando algum valor que muda a cada
     * execução do programa. Isso pode ser feito
     * utilizando a função time, passando NULL como
     * parâmetro, o que que retornará um valor
     * que representa o tempo atual do sistema.
     *
     * Quando seu programa precisar usar o gerador de
     * números pseudoaleatórios, lembre-se de invocar
     * srand APENAS UMA VEZ, normalmente, no início
     * da função main.
     */
    srand( time( NULL ) );

    /* Após a semeadura, cada invocação à rand gerará
     * um número pseudoaletório no intervalo de 0 a
     * RAND_MAX, macro definida em stdlib.h que expande
     * para um inteiro. Esse valor é dependente de
     * implementação, mas a garantia é que seja, no
     * mínimo, 32767.
     * https://en.cppreference.com/w/c/numeric/random/RAND_MAX
     */
    printf( "0 a %d: %d\n", RAND_MAX, rand() );

    /* Entretanto, normalmente precisamos que os valores
     * sejam gerados em um intervalo definido. Para isso
     * calculamos o resto da divisão inteira do valor
     * gerado pelo último valor do intervalo desejado.
     *
     * No exemplo abaixo, serão gerados 10 valores no
     * intervalo de 0 a 19.
     */
    for ( int i = 0; i < 10; i++ ) {
        printf( "0 a 19: %d\n", rand() % 20 );
    }

    /* A geração de valores aleatórios em um intervalo
     * fechado é feita abaixo, usando a função implementada
     * a seguir.
     */
    for ( int i = 0; i < 10; i++ ) {
        printf( "5 a 25: %d\n", randIntervalo( 5, 25 ) );
    }

    return 0;

}

int randIntervalo( int inicio, int fim ) {
    return inicio + ( rand() % ( fim - inicio + 1 ) );
}
