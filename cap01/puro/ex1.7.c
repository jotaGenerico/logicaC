#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int lado; 
	
	printf( "Valor do lado: " ); 
	scanf( "%d", &lado ); 
	
	int perimetro = 4 * lado; 
	int area = lado * lado; 
	
	printf( "Perimetro = %d\n", perimetro ); 
	printf( "Area = %d\n", area ); 
	
	return 0; 
	
}
