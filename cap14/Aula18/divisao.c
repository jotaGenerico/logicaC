int div( int a, int b ) {
    if ( a < b ) {
        return 0;
    }
    else {
        return div( a - b, b ) + 1;
    }
}
