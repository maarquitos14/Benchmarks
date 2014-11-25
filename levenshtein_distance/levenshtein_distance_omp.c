#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int final = 0;
int m, n;

int min(int a, int b) {
    return a < b ? a : b;
}

#pragma omp task out(*res) final( len_s < m - final || len_t < n - final )
void levenshteinDistance( char * s, int len_s, char * t, int len_t, int * res ) {
    int tmp;
    if( !len_s && !len_t ) {
        *res = 0;
        return;
    }

    if( !len_s ) {
        *res = len_t;
        return;
    }

    if( !len_t ) {
        *res = len_s;
        return;
    }

    int aux1, aux2, aux3;
    levenshteinDistance( s, len_s-1, t, len_t, &aux1 );
    levenshteinDistance( s, len_s, t, len_t-1, &aux2 );
    levenshteinDistance( s, len_s-1, t, len_t-1, &aux3 );

    if( s[len_s-1] == t[len_t-1] ) {
        tmp = 0;
    }
    else {
        tmp = 1;
    }

    #pragma omp taskwait
    *res = min( min( aux1+1, aux2+1 ), aux3+tmp );
}

int main( int argc, char * argv[] ) {
    if( argc < 3 ) {
        printf( "usage: %s string1 string2\n", argv[0] );
        exit(0);
    }
    char * s = argv[1];
    char * t = argv[2];
    m = strlen(s);
    n = strlen(t);
    if( argc == 4 ) {
        final = atoi(argv[3]);
    }
    int res = 0;
    double start = omp_get_wtime();
    levenshteinDistance( s, m, t, n, &res );
    #pragma omp taskwait
    double end = omp_get_wtime();
    printf("Levenshtein distance %d, time %f\n", res, end-start);
}
