#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float raio; 
	float pi = 3.141592; 
	
	printf( "Valor do raio do circulo: " ); 
	scanf( "%f", &raio ); 
	
	float diametro = 2 * raio; 
	float circunferencia = 2 * pi * raio; 
	float area = pi * (raio * raio); 
	
	printf( "Diametro = %.2f\n", diametro ); 
	printf( "Circunferencia = %.2f\n", circunferencia ); 
	printf( "Area = %.2f\n", area ); 
	
	return 0; 
	
}
