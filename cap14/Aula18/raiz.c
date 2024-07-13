int pows( int x, int n ) {
    if ( n == 0 ) {
        return 1;
    }
    else if ( n % 2 == 0 ) {       // par
        int y = pows( x, n / 2 );
        return y * y;
    }
    else {                       // impar
        int y = pows( x, ( n - 1 ) / 2 );
        return x * y * y;
    }
}
