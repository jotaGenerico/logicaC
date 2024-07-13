#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float lado; 
	
	printf( "Valor do lado: " ); 
	scanf( "%f", &lado ); 
	
	float perimetro = 4 * lado; 
	float area = lado * lado; 
	
	printf( "Perimetro = %.2f\n", perimetro ); 
	printf( "Area = %.2f\n", area ); 
	
	return 0; 
	
}
