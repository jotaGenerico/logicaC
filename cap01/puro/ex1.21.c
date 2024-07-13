#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int numero; 
	
	printf( "Forneca um numero inteiro: " ); 
	scanf( "%d", &numero ); 
	
	int sucessor = numero + 1; 
	int antecessor = numero - 1; 
	
	printf( "Sucessor de %d: %d\n", numero, sucessor ); 
	printf( "Antecessor de %d: %d\n", numero, antecessor ); 
	
	return 0; 
	
}
