#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>

int M, N;
int final = 0;

int min(int x, int y, int z) {
    if (x < y)
        return (x < z)? x : z;
    else
        return (y < z)? y : z;
}

#pragma omp task out(*res) final(m*n < (M-final)*(N-final))
void minCost(int cost[][N], int m, int n, int *res) {
    if (n < 0 || m < 0) {
        *res = INT_MAX;
    }
    else if (m == 0 && n == 0) {
        *res = cost[m][n];
    }
    else {
        int aux1 = 0, aux2 = 0, aux3 = 0;
        minCost(cost, m-1, n-1, &aux1);
        minCost(cost, m-1, n, &aux2);
        minCost(cost, m, n-1, &aux3);
        #pragma omp taskwait
        *res = cost[m][n] + min(aux1, aux2, aux3);
    }
}


int main(int argc, char * argv[]) {
	const char *filename;
	int i, j, res;
	
	if(argc<6) {
		printf("./%s filename M N final_row final_col\n", argv[0]);
		exit(0);
	}

    filename = argv[1];
    M = atoi(argv[2]);
    N = atoi(argv[3]);
    int final_row = atoi(argv[4]);
    int final_col = atoi(argv[5]);
    if(argc == 7) {
        final = atoi(argv[6]);
    }
	int cost[M][N];
	FILE *f = fopen(filename, "r");
	for(i=0;i<M;i++) {
        for(j=0;j<N;j++) {
		    fscanf(f, "%d", &cost[i][j]);
        }
    }
    double start = omp_get_wtime();
    minCost(cost, final_row, final_col, &res);
    #pragma omp taskwait
    double end = omp_get_wtime();
    printf(" %d, time %f\n", res, end-start);
    return 0;
}
