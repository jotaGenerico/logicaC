#include <stdio.h>

void f3(char helloworld[]){
    printf("%x\n", &hello); 
    f3(hello); 
}


void main(){

    char hello[] = "hello world"; 
    
    printf("from main: %x\n", &hello); 
    
    return; 
}
