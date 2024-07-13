#include <stdio.h>
#include<stdlib.h>

int main(void){

    char conversao;
    float valorC, valorF;

    printf( "Escolha uma operacao de acordo com o menu: \n" );
    printf( "\n"
    "                C) Celsius -> Fahrenheit;\n"
    "                F) Fahrenheit -> Celsius.\n");
    printf( "\nOpcao: ");
    scanf( " %c", &conversao );

    switch (conversao){

        case 'C':

            printf( "\nEntre com a temperatura em graus Celsius: " );
            scanf( "%f", &valorC );

            valorF = 1.8*valorC + 32;

            printf( "%.2f graus Celsius correspondem a %.2f graus Fahrenheit\n", valorC, valorF );

            break;

        case 'F':


            printf( "\nEntre com a temperatura em graus Fahrenheit: " );
            scanf( "%f", &valorF );

            valorC = (valorF - 32) / 1.8;

            printf( "%.2f graus Fahrenheit correspondem a %.2f graus Celsius\n", valorF, valorC );

            break;

        default:

            printf( "Opcao invalida!\n" );

            break;
    }

    return 0;

}
