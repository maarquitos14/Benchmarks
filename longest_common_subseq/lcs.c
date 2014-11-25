#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b)? a : b;
}

void lcs( char *X, char *Y, int m, int n, int * res ) {
    if ( m == 0 || n == 0 ) {
        *res = 0;
        return;
    }
    if ( X[m-1] == Y[n-1] ) {
        int aux = 0;
        lcs( X, Y, m-1, n-1, &aux );
        *res = aux + 1;
        return;
    }
    else {
        int aux1 = 0, aux2 = 0;
        lcs( X, Y, m, n-1, &aux1 );
        lcs( X, Y, m-1, n, &aux2 );
        *res = max( aux1, aux2 );
        return; 
    }
}

int main( int argc, char * argv[] ) {
    if( argc != 3 ) {
        printf( "usage: %s seq1 seq2\n", argv[0] );
        exit(0);
    }
    char * x = argv[1];
    char * y = argv[2];
    int res = 0;
    double start = omp_get_wtime();
    lcs(x, y, strlen(x), strlen(y), &res);
    double end = omp_get_wtime();
    printf( "Length of LCS %d, time %f\n", res, end-start );
    return 0;
}

