/* 
 * Arquivo: PonteirosTipos.c
 * Autor: Prof. Dr. David Buzatto
 */
 
#include <stdio.h>
#include <limits.h>
#include <math.h>

int main( void ) {

    printf( "char: %d\n", sizeof( char ) );
    printf( "signed char: %d\n", sizeof( signed char ) );
    printf( "unsigned char: %d\n", sizeof( unsigned char ) );
    printf( "short: %d\n", sizeof( short ) );
    printf( "short int: %d\n", sizeof( short int ) );
    printf( "signed short: %d\n", sizeof( signed short ) );
    printf( "signed short int: %d\n", sizeof( signed short int ) );
    printf( "unsigned short: %d\n", sizeof( unsigned short ) );
    printf( "unsigned short int: %d\n", sizeof( unsigned short int ) );
    printf( "int: %d\n", sizeof( int ) );
    printf( "signed: %d\n", sizeof( signed ) );
    printf( "signed int: %d\n", sizeof( signed int ) );
    printf( "unsigned: %d\n", sizeof( unsigned ) );
    printf( "unsigned int: %d\n", sizeof( unsigned int ) );
    printf( "long: %d\n", sizeof( long ) );
    printf( "long int: %d\n", sizeof( long int ) );
    printf( "signed long: %d\n", sizeof( signed long ) );
    printf( "signed long int: %d\n", sizeof( signed long int ) );
    printf( "unsigned long: %d\n", sizeof( unsigned long ) );
    printf( "unsigned long int: %d\n", sizeof( unsigned long int ) );
    printf( "long long: %d\n", sizeof( long long ) );
    printf( "long long int: %d\n", sizeof( long long int ) );
    printf( "signed long long: %d\n", sizeof( signed long long ) );
    printf( "signed long long int: %d\n", sizeof( signed long long int ) );
    printf( "unsigned long long: %d\n", sizeof( unsigned long long ) );
    printf( "unsigned long long int: %d\n", sizeof( unsigned long long int ) );
    printf( "float: %d\n", sizeof( float ) );
    printf( "double: %d\n", sizeof( double ) );
    printf( "long double: %d\n", sizeof( long double ) );

    printf("CHAR_BIT   = %d\n", CHAR_BIT);
    printf("MB_LEN_MAX = %d\n", MB_LEN_MAX);
    printf("\n");

    printf("CHAR_MIN   = %+d\n", CHAR_MIN);
    printf("CHAR_MAX   = %+d\n", CHAR_MAX);
    printf("SCHAR_MIN  = %+d\n", SCHAR_MIN);
    printf("SCHAR_MAX  = %+d\n", SCHAR_MAX);
    printf("UCHAR_MAX  = %u\n",  UCHAR_MAX);
    printf("\n");

    printf("SHRT_MIN   = %+d\n", SHRT_MIN);
    printf("SHRT_MAX   = %+d\n", SHRT_MAX);
    printf("USHRT_MAX  = %u\n",  USHRT_MAX);
    printf("\n");

    printf("INT_MIN    = %+d\n", INT_MIN);
    printf("INT_MAX    = %+d\n", INT_MAX);
    printf("UINT_MAX   = %u\n",  UINT_MAX);
    printf("\n");

    printf("LONG_MIN   = %+ld\n", LONG_MIN);
    printf("LONG_MAX   = %+ld\n", LONG_MAX);
    printf("ULONG_MAX  = %lu\n",  ULONG_MAX);
    printf("\n");

    printf("LLONG_MIN  = %+lld\n", LLONG_MIN);
    printf("LLONG_MAX  = %+lld\n", LLONG_MAX);
    printf("ULLONG_MAX = %llu\n",  ULLONG_MAX);
    printf("\n");

    return 0;

}
