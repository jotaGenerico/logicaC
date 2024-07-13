#include <stdio.h>
#include <stdlib.h>

int main(void){

    float peso;
    float totalPessoas = 0;
    float pessoaMaisPesada = 0;
    float pesoTotal = 0;
    float mediaPesos = 0;
    int contador = 1;
    int primeiro = 1;

    do{
        printf( "Entre com o peso da pessoa %02d: ", contador++ );
        scanf( "%f", &peso );

        if(peso < 0){
            if(primeiro){     
                mediaPesos = 0;           
                pessoaMaisPesada = 0;                
            }

            break;
        }
        if(primeiro){
            pessoaMaisPesada = peso;
            primeiro = 0;
        }
        if(peso >= 60){
            totalPessoas++;
            pesoTotal += peso;
            pessoaMaisPesada = (peso > pessoaMaisPesada)?peso:pessoaMaisPesada;            
        }
    }
    while(peso >= 0);

    if (totalPessoas > 0){
        mediaPesos = pesoTotal / totalPessoas;
    }
    else {
        mediaPesos = 0;
    }
    
    printf("Media dos pesos acima de 60kg: %.2f\n", mediaPesos );
    printf("A pessoa mais pesada possui %.2fkg\n", pessoaMaisPesada );

    return 0;
}