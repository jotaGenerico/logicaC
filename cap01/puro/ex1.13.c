#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float numero1; 
	float numero2; 
	
	printf( "Primeiro numero: " ); 
	scanf( "%f", &numero1 ); 
	
	printf( "Segundo numero: " ); 
	scanf( "%f", &numero2 ); 
	
	float soma = numero1 + numero2 ; 
	float subtracao = numero1 - numero2; 
	float multiplicacao = numero1 * numero2; 
	float divisao = numero1 / numero2; 
	
	printf( "%.2f + %.2f = %.2f\n", numero1, numero2, soma ); 
	printf( "%.2f - %.2f = %.2f\n", numero1, numero2, subtracao ); 
	printf( "%.2f * %.2f = %.2f\n", numero1, numero2, multiplicacao ); 
	printf( "%.2f / %.2f = %.2f\n", numero1, numero2, divisao ); 
	
	return 0; 
}
