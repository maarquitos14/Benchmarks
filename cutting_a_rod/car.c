#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <limits.h>

// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b)? a : b;}

/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
void cutRod(int *price, int n, int * res) {
    if (n <= 0) {
        *res = 0;
        return;
    }
    int max_val = INT_MIN;

    // Recursively cut the rod in different pieces and compare different 
    // configurations
    for (int i = 0; i<n; i++) {
        int aux = INT_MIN;
        cutRod(price, n-i-1, &aux);
        max_val = max(max_val, price[i] + aux);
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
	int price[n];
	FILE *f = fopen(filename, "r");
    int i;
	for( i=0; i<n; i++ )
		fscanf(f, "%d", &price[i]);
    int res = 0;
    double start = omp_get_wtime();
    cutRod( price, n, &res );
    double end = omp_get_wtime();
    printf("%d, time %f\n", res, end-start);
    fclose(f);
    return 0;
}
