#include <stdio.h>
#include <stdlib.h>

int main(void){

    float nota1, nota2, optativa, media;

    printf( "Nota Av. 1: " );
    scanf( "%f", &nota1 );

    printf( "Nota Av. 2: " );
    scanf( "%f", &nota2 );

    printf( "Nota Optativa: " );
    scanf( "%f", &optativa );

    if(nota1 >= nota2){

        media = (nota1 + (nota2 > optativa?nota2:optativa)) / 2;

    }else{

        media = (nota2 + (nota1 > optativa?nota1:optativa)) / 2;

    }

    if(media >= 6){

        printf( "Media: %.2f\n", media );
        printf( "Aprovado!\n" );

    }else if(media < 4){

        printf( "Media: %.2f\n", media );
        printf( "Reprovado...\n" );

    }else{

        printf( "Media: %.2f\n", media );
        printf( "Exame.\n" );
    }
    
    return 0;

}