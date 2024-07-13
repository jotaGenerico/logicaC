#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int largura; 
	int altura; 
	
	printf( "Valor da largura: " ); 
	scanf( "%d", &largura ); 
	printf( "Valor da altura: " ); 
	scanf( "%d", &altura ); 
	
	int perimetro = ( 2 * largura ) + ( 2 * altura ); 
	int area = largura * altura; 
	
	printf( "Perimetro = %d\n", perimetro ); 
	printf( "Area = %d\n", area ); 
	
	return 0; 
	
}
