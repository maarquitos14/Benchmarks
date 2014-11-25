#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int ori_n;
int final = 0;

int max(int a, int b) { return (a > b)? a : b;}

#pragma omp task memo(n+1, n) out(*res) final(n < ori_n - final)
void maxProd(int n, int * res) {
    if (n == 0 || n == 1) { 
        *res = 0;
        return;
    }

    int max_val = 0, i;
    int tmp[n];
    for ( i = 1; i < n; i++ ) {
        maxProd(n-i, &tmp[i]);
    }

    #pragma omp taskwait
    for ( i=1; i<n; i++ ) {
        max_val = max(max_val, max(i*(n-i), tmp[i]*i));
    }
    *res = max_val;
}

int main( int argc, char * argv[] ) {
    if( argc < 2 ) {
        printf("usage: %s n\n", argv[0]);
        exit(0);
    }
    int n = atoi(argv[1]);
    ori_n = n;
    if( argc == 3 ) {
        final = atoi(argv[2]);
    }
    int res = 0;
    double start = omp_get_wtime();
    maxProd( n, &res );
    #pragma omp taskwait
    double end = omp_get_wtime();
    printf("%d, time %f\n", res, end-start);
    return 0;
}
