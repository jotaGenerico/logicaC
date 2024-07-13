#include <stdio.h>
#include <stdlib.h>

int main(void){

    float num1;
    float num2;
    char operacao;

    printf( "N1: " );
    scanf( "%f", &num1 );

    printf( "N: " );
    scanf( "%f", &num2 );

    printf( "Escolha uma operacao de acordo com o menu:\n"
            "\n"
            "    +) Adicao;\n"
            "    -) Subtracao;\n"
            "    *) Multiplicacao;\n"
            "    /) Divisao.\n" );
    printf( "\nOperacao: " );
    scanf( " %c", &operacao );

    switch (operacao){

        case '+':

            printf( "%.2f + %.2f = %.2f\n", num1, num2, num1 + num2 );
            break;

        case '-':

            printf( "%.2f - %.2f = %.2f\n", num1, num2, num1 -num2 );
            break;

        case '*':

            printf( "%.2f * %.2f = %.2f\n", num1, num2, num1 * num2 );
            break;

        case '/':

            printf( "%.2f / %.2f = %.2f\n", num1, num2, num1 / num2 );
            break;

        default:

            printf( "Opcao invalida!\n" );
            break;

    }

    return 0;

}