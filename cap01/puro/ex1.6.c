#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int num1; 
	int num2; 


	printf( "Primeiro numero: " ); 
	scanf( "%d", &num1); 


	printf( "Segundo numero: " ); 
	scanf( "%d", &num2 ); 


	int soma = num1 + num2; 
	int subtracao = num1 - num2; 
	int multiplicacao = num1 * num2; 
	int divisao = num1 / num2;


	printf( "%d + %d = %d\n", num1, num2, soma ); 
	printf( "%d - %d = %d\n", num1, num2, subtracao ); 
	printf( "%d * %d = %d\n", num1, num2, multiplicacao ); 
	printf( "%d / %d = %d\n", num1, num2, divisao ); 
	
	return 0; 
}
