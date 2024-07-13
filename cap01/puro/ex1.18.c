#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float maior; 
	float menor; 
	
	printf( "Valor da diagonal maior: " ); 
	scanf( "%f", &maior ); 
	
	printf( "Valor da diagonal menor: " ); 
	scanf( "%f", &menor ); 
	
	float area = ( maior * menor ) / 2; 
	
	printf( "Area = %.2f\n", area ); 
	
	return 0; 
	
}
