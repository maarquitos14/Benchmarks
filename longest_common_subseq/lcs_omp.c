#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int ori_m, ori_n;
int final = 0;

int max(int a, int b)
{
    return (a > b)? a : b;
}

#pragma omp task out(*res) final(m < ori_m - final || n < ori_n - final)
void lcs( char *X, char *Y, int m, int n, int * res ) {
    if ( m == 0 || n == 0 ) {
        *res = 0;
        return;
    }
    if ( X[m-1] == Y[n-1] ) {
        int aux = 0;
        lcs( X, Y, m-1, n-1, &aux );
        #pragma omp taskwait
        *res = aux + 1;
        return;
    }
    else {
        int aux1 = 0, aux2 = 0;
        lcs( X, Y, m, n-1, &aux1 );
        lcs( X, Y, m-1, n, &aux2 );
        #pragma omp taskwait
        *res = max( aux1, aux2 );
        return; 
    }
}

int main( int argc, char * argv[] ) {
    if( argc < 2)  {
        printf( "usage: %s filename\n", argv[0] );
        exit(0);
    }

    const char *filename = argv[1];
	FILE *f = fopen(filename, "r");
    char x[1000];
    char y[1000];
    fscanf(f, "%s", &x); 
    fscanf(f, "%s", &y); 
    ori_m = strlen(x);
    ori_n = strlen(y);
    if( argc == 3 ) {
        final = atoi(argv[2]);
    }
    int res = 0;
    double start = omp_get_wtime();
    lcs(x, y, ori_m, ori_n, &res);
    #pragma omp taskwait
    double end = omp_get_wtime();
    printf( "Length of LCS %d, time %f\n", res, end-start );
    return 0;
}


