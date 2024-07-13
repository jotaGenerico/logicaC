#include <stdio.h>
#include <stdlib.h>

int main(void){

    float peso, altura, imc;

    printf( "Entre com seu peso em quilogramas: " );
    scanf( "%f", &peso );

    printf( "Entre com sua altura em metros: " );
    scanf( "%f", &altura );

    imc = peso / (altura * altura);
    
    if(imc < 17.0){

        printf( "IMC: %.2f\n", imc );
        printf( "Voce esta muito abaixo do peso ideal!\n" );

    }else if(imc >= 17 && imc < 18.5){

        printf( "IMC: %.2f\n", imc );
        printf( "Voce esta abaixo do peso ideal!\n" );

    }else if(imc >= 18.5 && imc < 25){

        printf( "IMC: %.2f\n", imc );
        printf( "Parabens! Voce esta em seu peso normal!\n" );

    }else if(imc >= 25 && imc < 30){

        printf( "IMC: %.2f\n", imc );
        printf( "Atencao, voce esta acima de seu peso (sobrepeso)!\n" );
        
    }else if(imc >= 30 && imc < 35){

        printf( "IMC: %.2f\n", imc );
        printf( "Cuidado! Obesidade grau I!\n" );

    }else if(imc >= 35 && imc < 40){

        printf( "IMC: %.2f\n", imc );
        printf( "Cuidado! Obesidade grau II!\n" );

    }else{

        printf( "IMC: %.2f\n", imc );
        printf( "Muito cuidade!!! Obesidade grau III!\n" );
        
    }

    return 0;

}