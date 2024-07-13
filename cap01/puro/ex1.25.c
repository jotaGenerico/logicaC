#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float fahrenheit;
	
	printf( "Temperatura em graus Fahrenheit: " ); 
	scanf( "%f", &fahrenheit ); 
	
	float celsius = (fahrenheit - 32) / 1.8; 
	
	printf( "%.2f graus Fahrenheit correspondem a %.2f graus Celsius\n", fahrenheit, celsius ); 
	
	return 0; 
	
}
