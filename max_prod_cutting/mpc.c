#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int max(int a, int b) { return (a > b)? a : b;}

void maxProd(int n, int * res) {
    if (n == 0 || n == 1) { 
        *res = 0;
        return;
    }

    int max_val = 0, i;
    for ( i = 1; i < n; i++ ) {
        int tmp = 0;
        maxProd(n-i, &tmp);
        max_val = max(max_val, max(i*(n-i), tmp*i));
    }

    *res = max_val;
}

int main( int argc, char * argv[] ) {
    if( argc != 2 ) {
        printf("usage: %s n\n", argv[0]);
        exit(0);
    }
    int n = atoi(argv[1]);
    int res = 0;
    double start = omp_get_wtime();
    maxProd( n, &res );
    double end = omp_get_wtime();
    printf("%d, time %f\n", res, end-start);
    return 0;
}
