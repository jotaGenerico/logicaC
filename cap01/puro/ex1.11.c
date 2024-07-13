#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int maior; 
	int menor; 
	
	printf( "Valor da diagonal maior: " ); 
	scanf( "%d", &maior ); 
	printf( "Valor da diagonal menor: " ); 
	scanf( "%d", &menor ); 
	
	int area = ( maior * menor ) / 2; 
	
	printf( "Area = %d\n", area ); 
	
	return 0; 
	
}
