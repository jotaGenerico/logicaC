#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	
	char hello[] = "hello world"; 	
	printf("from main: %d\n", &hello); 
	
	char *hello2 = malloc(sizeof(hello)); 
	strcpy(hello, hello2); 
	print("hello2: %x\n", hello2); 
	
	char *hello3 = hello2 + 6; 
	printf("from hello2: %s\n", hello2); 
	printf("from hello3: %s\n", hello3); 
	
	return; 
	
	
}
