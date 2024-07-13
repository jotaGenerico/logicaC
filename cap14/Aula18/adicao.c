int add( int a, int b ) {
    if ( b == 0 ) {
        return a;
    }
    else {
        return add( a, b - 1 ) + 1;
    }
}
