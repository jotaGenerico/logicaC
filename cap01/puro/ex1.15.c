#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float largura; 
	float altura; 
	
	printf( "Valor da largura: " ); 
	scanf( "%f", &largura ); 
	
	printf( "Valor da altura: " ); 
	scanf( "%f", &altura ); 
	
	float perimetro = ( 2 * largura ) + ( 2 * altura ); 
	float area = largura * altura; 
	
	printf( "Perimetro = %.2f\n", perimetro ); 
	printf( "Area = %.2f\n", area ); 
	
	return 0; 
	
}
