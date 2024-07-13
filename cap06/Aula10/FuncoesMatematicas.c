/*
 * Arquivo: FuncoesMatematicas.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* math.h é o cabeçalho necessário para utilizar as
 * funções matemáticas na linguagem C.
 */

int main( void ) {

    /* constante matemática PI
     * a palavra chave "const" indica que o valor de uma
     * variável não pode ser alterada após a atribuição.
     *
     * recomenda-se que o valor da constante seja gerado
     * usando a função do arco cosseno.
     */
    const double PI = acos(-1);

    printf( "**** modulo ****\n" );

    // função abs: retorna o valor absoluto de um inteiro
    printf( "abs(+3)     = %d\n", abs(+3) );
    printf( "abs(-3)     = %d\n\n", abs(-3) );

    // função fabs: retorna o valor absoluto de um decimal
    printf( "fabs(+3)    = %f\n", fabs(+3.0) );
    printf( "fabs(-3)    = %f\n\n", fabs(-3.0) );



    printf( "**** minimo e maximo ****\n" );

    /* função fmin: retorna o menor valor entre dois valores
     * decimais comparados.
     */
    printf( "fmin(2, 1)  = %.2f\n", fmin(2, 1) );

    /* função fmax: retorna o maior valor entre dois valores
     * decimais comparados.
     */
    printf( "fmax(2, 1)  = %.2f\n\n", fmax(2, 1) );



    printf( "**** potenciacao e radiciacao ****\n" );

    // função pow (power): eleva uma base a um expoente
    printf( "pow(2, 10)  = %.2f\n", pow(2, 10) );
    printf( "pow(1024, 1.0/10) = %.2f\n", pow(1024, 1.0/10) );

    /* função sqrt (square root): calcula a raiz quadrada de um
     * valor decimal.
     */
    printf( "sqrt(100)   = %.2f\n", sqrt(100) );

    /* função cbrt (cube root): calcula a raiz cúbica de um valor
     * decimal.
     */
    printf( "cbrt(729)   = %.2f\n\n", cbrt(729) );



    printf( "**** funcoes trigonometricas ****\n" );

    /* função sin (sine): calcula o seno de um ângulo com medida
     * em radianos.
     */
    printf( "sin(pi/6)   = %.2f\n", sin(PI/6));    // 30 graus

    /* função cos (cosine): calcula o cosseno de um ângulo com
     * medida em radianos.
     */
    printf( "cos(pi/3)   = %.2f\n", cos(PI/3));    // 60 graus

    /* função tan (tangent): calcula a tangente de um ângulo com
     * medida em radianos.
     */
    printf( "tan(pi/4)   = %.2f\n\n", tan(PI/4)); // 45 graus



    printf( "**** funcoes trigonometricas " );
    printf( "inversas (funcoes arco) ****\n" );

    /* função asin (arcsine): calcula o grau em radianos de um
     * seno.
     */
    printf( "asin(0.5)   = %.2f radianos => %.2f graus\n",
            asin(0.5), 180/PI * asin(0.5) );

    /* função acos (arccosine): calcula o grau em radianos de
     * um cosseno.
     */
    printf( "acos(0.5)   = %.2f radianos => %.2f graus\n",
            acos(0.5), 180/PI * acos(0.5) );

    /* função atan (arctangent): calcula o grau em radianos
     * de uma tangente.
     */
    printf( "atan(1)     = %.2f radianos => %.2f graus\n\n",
            atan(1), 180/PI * atan(1) );

    /* função hypot (hypotenuse): calcula o valor da hipotenusa
     * com base no valor dos dois catetos.
     */
    printf( "hypot(3, 4) = %f\n", hypot(3, 4) );

    /* função atan2 (arctangent2): obtém o ângulo de uma
     * coordenada cartesiana.
     */
    printf( "atan2(4, 3) = (3; 4) cartesiano " );
    printf( "corresponde a (%.2f, %.2f) polar\n",
            hypot(4, 3), atan2(4, 3) );
    printf( "              note que %.2f radianos => ", atan2(4, 3) );
    printf( "%.2f graus\n\n", 180/PI * atan2(4, 3) );



    printf( "**** funcoes de arredondamento ****\n" );

    /* função ceil: arredonda um número decimal para o maior
     * inteiro mais próximo.
     */
    printf( "ceil(+2.4)  =  %.2f\n", ceil(2.4) );
    printf( "ceil(-2.4)  = %.2f\n\n", ceil(-2.4) );

    /* função floor: arredonda um número decimal para o menor
     * inteiro mais próximo.
     */
    printf( "floor(+2.7) =  %.2f\n", floor(2.7) );
    printf( "floor(-2.7) = %.2f\n\n", floor(-2.7) );

    // função trunc: remove a parte decimal
    printf( "trunc(+2.7) =  %.2f\n", trunc(2.7) );
    printf( "trunc(-2.7) = %.2f\n\n", trunc(-2.7) );

    // função round: arredonda para o inteiro mais próximo
    printf( "round(+2.3) = %.2f\n", round(2.3) );
    printf( "round(+2.5) = %.2f\n", round(2.5) );
    printf( "round(+2.7) = %.2f\n", round(2.7) );
    printf( "round(-2.3) = %.2f\n", round(-2.3) );
    printf( "round(-2.5) = %.2f\n", round(-2.5) );
    printf( "round(-2.7) = %.2f\n", round(-2.7) );

    return 0;

}
