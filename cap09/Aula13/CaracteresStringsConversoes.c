/* 
 * Arquivo: CaracteresStringsConversoes.c
 * Autor: Prof. Dr. David Buzatto
 */

#include <stdio.h>
#include <stdlib.h>

/* stdlib.h é o cabeçalho necessário para utilizar as
 * funções de conversão de Strings em valores numéricos.
 */

int main( void ) {

    /* double atof( const char* str )
     * Retorna um double com o valor representado pela string str.
     */
    float vFloat = atof( "12.5" );
    double vDouble = atof( "29.75" );

    /* int atoi( const char *str );
     * long atol( const char *str );
     * long long atoll( const char *str );
     * Retorna um inteiro com o valor representado pela string str.
     */
    int vInt = atoi( "10" );
    long vLong = atol( "248" );
    long long vLongLong = atoll( "1795418" );

    // imprimindo...
    printf( "vFloat: %f\n", vFloat );
    printf( "vDouble: %lf\n", vDouble );
    printf( "vInt: %d\n", vInt );
    printf( "vLong: %li\n", vLong );
    printf( "vLongLong: %lli\n", vLongLong );

    return 0;

}
