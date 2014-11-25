#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <limits.h>
#include <string.h>

int ori_n;
int final = 0;

int max(int a, int b) { return (a > b)? a : b;}

#pragma omp task out(*res) memo(n+1, n) final(n < ori_n - final)
void cutRod(int *price, int n, int * res) {
    if (n <= 0) {
        *res = 0;
        return;
    }
    int max_val = INT_MIN;
    int aux[n];
    memset(aux, INT_MIN, n);
    int i;
    for(i = 0; i<n; i++) {
        cutRod(price, n-i-1, &aux[i]);
    }
    #pragma omp taskwait
    for(i = 0; i<n; i++) {
        max_val = max(max_val, price[i] + aux[i]);
    }

    *res = max_val;
}

int main( int argc, char * argv[] ) {
    if( argc < 3) {
        printf("usage: %s filename size\n", argv[0]);
        exit(0);
    }
    char * filename = argv[1];
    int n = atoi( argv[2] );
    ori_n = n;
    if( argc == 4 ) {
        final = atoi( argv[3] );
    }
	int price[n];
	FILE *f = fopen(filename, "r");
    int i;
	for( i=0; i<n; i++ )
		fscanf(f, "%d", &price[i]);
    int res = 0;
    double start = omp_get_wtime();
    cutRod( price, n, &res );
    #pragma omp taskwait
    double end = omp_get_wtime();
    printf("%d, time %f\n", res, end-start);
    fclose(f);
    return 0;
}
