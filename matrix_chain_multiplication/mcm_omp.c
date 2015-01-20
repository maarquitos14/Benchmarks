#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>

int final = 0;
int ori_i, ori_j;

#pragma omp task out(*res) final(i > ori_i + final || j < ori_j - final)
void MatrixChainOrder(int * p, int i, int j, int * res) {
    if(i == j) {
        *res = 0;
        return;
    }

    int k;
    int min = INT_MAX;
    int count[j];
    int aux1[j], aux2[j];

    for (k = i; k < j; k++) {
        MatrixChainOrder(p, i, k, &aux1[k]);
        MatrixChainOrder(p, k+1, j, &aux2[k]);
        count[k] = p[i-1]*p[k]*p[j];
    }

    #pragma omp taskwait
    for (k = i; k < j; k++) {
        count[k] += aux1[k] + aux2[k];
        if (count[k] < min) {
            min = count[k];
        }
    }

    *res = min;
}

int main( int argc, char * argv[] ) {
	const char *filename;
	int n, i, res;
	
	if(argc < 3) {
		printf("./%s filename size\n", argv[0]);
		exit(0);
	}
    filename = argv[1];
    n = atoi(argv[2]);

    if(argc == 4) {
        final = atoi(argv[3]);
    }

	int dimensions[n];
	FILE *f = fopen(filename, "r");
	for(i=0;i<n;i++)
		fscanf(f, "%d", &dimensions[i]);

    ori_i = 1;
    ori_j = n-1;
    double start = omp_get_wtime();
    MatrixChainOrder(dimensions, 1, n-1, &res);
    #pragma omp taskwait
    double end = omp_get_wtime();
    printf("Minimum number of multiplications is %d, time %f\n", res, end-start); 
}
