#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float baseMaior; 
	float baseMenor; 
	float altura; 
	
	printf( "Valor da base maior: " ); 
	scanf( "%f", &baseMaior ); 
	
	printf( "Valor da base menor: " ); 
	scanf( "%f", &baseMenor ); 
	
	printf( "Valor da altura: " ); 
	scanf( "%f", &altura ); 
	
	float area = ((baseMaior + baseMenor) * altura) / 2; 
	
	printf( "Area = %.2f\n", area ); 
	
	return 0; 
	
	}
