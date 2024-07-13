int mult( int a, int b ){
    if ( a == 0 || b == 0 ) {
        return 0;
    }
    else {
        return mult( a - 1, b ) + b;
    }
}
