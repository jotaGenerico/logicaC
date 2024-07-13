#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int baseMaior; 
	int baseMenor; 
	int altura; 
	
	printf( "Valor da base maior: " ); 
	scanf( "%d", &baseMaior ); 
	printf( "Valor da base menor: " ); 
	scanf( "%d", &baseMenor );
	printf( "Valor da altura: " ); 
	scanf( "%d", &altura ); 
	
	int area = ((baseMaior + baseMenor) * altura) / 2; 
	
	printf( "Area = %d\n", area ); 
	
	return 0; 
	
}

