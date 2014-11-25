#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int *memo;
int ori_n;

int max(int a, int b) { return (a > b)? a : b;}

void maxProd(int n, int * res) {
    if (n == 0 || n == 1) { 
        *res = 0;
        return;
    }

    int max_val = 0, i;
    for ( i = 1; i < n; i++ ) {
        int tmp = 0;
        if(memo[n-i] == -1) {
            maxProd(n-i, &tmp);
            memo[n-i] = tmp;
        }
        max_val = max(max_val, max(i*(n-i), memo[n-i]*i));
    }

    *res = max_val;
}

int main( int argc, char * argv[] ) {
    if( argc != 2 ) {
        printf("usage: %s n\n", argv[0]);
        exit(0);
    }
    int n = atoi(argv[1]);
    ori_n = n+1;
    memo = calloc(ori_n, sizeof(int));
    memset(memo, -1, ori_n*sizeof(int));
    int res = 0;
    double start = omp_get_wtime();
    maxProd( n, &res );
    double end = omp_get_wtime();
    printf("%d, time %f\n", res, end-start);
    return 0;
}
