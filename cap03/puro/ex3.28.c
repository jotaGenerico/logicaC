#include <stdio.h>
#include <stdlib.h>

int main(void){

    float saldo = 0;
    float deposito = 0;
    float saque = 0;

    int loop = 1;
    int operacao;

    printf( "Saldo inicial: ");
    scanf( "%f", &saldo );    

    do{
        printf( "Operacoes:\n"
                "   1) Deposito;\n"
                "   2) Saque;\n"
                "   3) Fim.\n" );
        printf( "\nOperacao desejada: " );
        scanf( "%d", &operacao );

        switch (operacao){
            case 1:
                printf( "Valor a depositar: " );
                scanf( "%f", &deposito );
                saldo += deposito;
                break;

            case 2:
                printf( "Valor a sacar: " );
                scanf( "%f", &saque );
                saldo -= saque;
                break;

            case 3:
                loop = 0;
                break;

            default:
                printf( "Operacao invalida\n" );
                break;
        }
        
    }while(loop);

    if(saldo > 0){
        printf( "Saldo final: R$%.2f\n", saldo );
        printf( "Conta preferencial.\n" );
    }
    else if(saldo < 0){
        printf( "Saldo final: -R$%.2f\n", saldo * -1 );
        printf( "Conta devedora.\n" );
    }
    else{
        printf( "Saldo final: R$%.2f\n", saldo );
        printf( "Sem saldo.\n" );
    }

    return 0;    
}