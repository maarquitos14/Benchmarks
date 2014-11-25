#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>

int ori_n;
int final = 0;

#pragma omp task out(*res) final(n < ori_n - final)
void lis_smaller(int * a, int n, int x, int * res) {
    if (n == 0) {
        *res = 0;
        return;
    }
    int aux1 = 0, aux2 = 0;
    lis_smaller(a, n-1, x, &aux1);
    if(x == -1) {
        lis_smaller(a, n-1, n-1, &aux2);
    }
    else if(a[n-1] < a[x]) {
        lis_smaller(a, n-1, n-1, &aux2);
    }
    #pragma omp taskwait
    if(x == -1 || a[n-1] < a[x]) {
        aux2++;
    }
    *res = aux1 > aux2 ? aux1 : aux2;
}

void lis(int * a, int n, int * res) {
    if(!n) {
        *res = 0;
        return;
    }
    lis_smaller(a, n, -1, res);
    #pragma omp taskwait
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
