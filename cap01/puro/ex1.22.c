#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float produto; 
	
	printf( "Valor do produto: " ); 
	scanf( "%f", &produto); 
	
	float final = produto - (produto * 0.09); 
	
	printf( "Preco de venda com 9%% de desconto: %.2f\n", final ); 
	
	return 0; 
	
}
