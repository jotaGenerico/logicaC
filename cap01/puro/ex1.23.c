#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int anoNascimento; 
	int anoAtual; 
	
	printf( "Ano de nascimento: " ); 
	scanf( "%d", &anoNascimento ); 
	
	printf( "Ano atual: " ); 
	scanf( "%d", &anoAtual ); 
	
	int idade = anoAtual - anoNascimento; 
	
	printf( "Idade aproximada: %d anos", idade ); 
	
	return 0; 
	
}
