int sub( int a, int b ) {
    if ( b == 0 ) {
        return a;
    }
    else {
        return sub( a, b - 1 ) - 1;
    }
}
