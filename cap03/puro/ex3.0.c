 #include <stdio.h>
 #include <stdlib.h>

 int main(void){

    int i = 0;
    printf( "%d\n", i );

    i++;
    printf( "%d ", i );

    ++i;
    printf( "%d\n", i );

    printf( "%d ", i++ );
    printf( "%d\n", i );

    printf( "%d ", ++i );
    printf( "%d\n", i );
    
    return 0;

 }
