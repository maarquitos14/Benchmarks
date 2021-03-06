#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>

void MatrixChainOrder(int * p, int i, int j, int * res) {
    if(i == j) {
        *res = 0;
        return;
    }

    int k;
    int min = INT_MAX;
    int count;

    for (k = i; k < j; k++) {
        int aux1 = 0, aux2 = 0;
        MatrixChainOrder(p, i, k, &aux1);
        MatrixChainOrder(p, k+1, j, &aux2);
        count = aux1 + aux2 + p[i-1]*p[k]*p[j];
        if (count < min) {
            min = count;
        }
    }

    *res = min;
}

int main( int argc, char * argv[] ) {
	const char *filename;
	int n, i, res;
	
	if(argc!=3) {
		printf("./%s filename size\n", argv[0]);
		exit(0);
	}

    filename = argv[1];
    n = atoi(argv[2]);
	int dimensions[n];
	FILE *f = fopen(filename, "r");
	for(i=0;i<n;i++)
		fscanf(f, "%d", &dimensions[i]);

    double start = omp_get_wtime();
    MatrixChainOrder(dimensions, 1, n-1, &res);
    double end = omp_get_wtime();
    printf("Minimum number of multiplications is %d, time %f\n", res, end-start); 
}
