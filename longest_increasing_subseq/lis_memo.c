#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>
#include <string.h>

int *memo;
int dim;

void lis_smaller(int * a, int n, int x, int * res) {
    if (n == 0) {
        *res = 0;
        return;
    }
    int aux1 = 0, aux2 = 0;
    if(memo[(n-1)*dim+x+1] == -1) {
        lis_smaller(a, n-1, x, &aux1);
        memo[(n-1)*dim+x+1] = aux1;
    }
    if(x == -1) {
        if(memo[(n-1)*dim+(n-1)+1] == -1) {
            lis_smaller(a, n-1, n-1, &aux2);
            memo[(n-1)*dim+(n-1)+1] = aux2;
        }
        *res = memo[(n-1)*dim+x+1] > memo[(n-1)*dim+(n-1)+1]+1 ? memo[(n-1)*dim+x+1] : memo[(n-1)*dim+(n-1)+1]+1;
        return;
    }
    else if(a[n-1] < a[x]) {
        if(memo[(n-1)*dim+(n-1)+1] == -1) {
            lis_smaller(a, n-1, n-1, &aux2);
            memo[(n-1)*dim+(n-1)+1] = aux2;
        }
        *res = memo[(n-1)*dim+x+1] > memo[(n-1)*dim+(n-1)+1]+1 ? memo[(n-1)*dim+x+1] : memo[(n-1)*dim+(n-1)+1]+1;
        return;
    }
    *res = memo[(n-1)*dim+x+1] > aux2 ? memo[(n-1)*dim+x+1] : aux2;
}

void lis(int * a, int n, int * res) {
    if(!n) {
        *res = 0;
        return;
    }
    lis_smaller(a, n, -1, res);
}

int main( int argc, char * argv[] ) {
    if( argc != 3) {
        printf("usage: %s filename size\n", argv[0]);
        exit(0);
    }
    char * filename = argv[1];
    int n = atoi( argv[2] );
    dim = n+1;
    memo = calloc(dim*dim, sizeof(int));
    memset(memo, -1, dim*dim*sizeof(int));
	int seq[n];
	FILE *f = fopen(filename, "r");
    int i;
	for( i=0; i<n; i++ )
		fscanf(f, "%d", &seq[i]);
    int res = 0;
    double start = omp_get_wtime();
    lis( seq, n, &res );
    double end = omp_get_wtime();
    printf("Length of LIS is %d, time %f\n", res, end-start);
    fclose(f);
    return 0;
}
