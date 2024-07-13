#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float hora; 
	float aulas; 
	float inss; 
	
	printf( "Valor da hora/aula: " ); 
	scanf( "%f", &hora ); 
	
	printf( "Quantidade de aulas: " ); 
	scanf( "%f", &aulas ); 
	
	printf( "Porcentagem de desconto do INSS: " ); 
	scanf( "%f", &inss ); 
	
	float salario = (hora * aulas) - (hora * aulas * (inss / 100)); 
	
	printf( "Salario Liquido: %.2f\n", salario ); 
	
	return 0; 
	
}
