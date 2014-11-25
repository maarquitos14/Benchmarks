#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#pragma omp task memo(n+1, n%5) out(*res)
void synthetic(int n, int *res) {
	if(n==0) *res = 1;
	else {
        int tmp1, tmp2;
        if(n-2 >= 0) {
            synthetic(n-2, &tmp1);
        }
        if(n-1 >= 0) {
            synthetic(n-1, &tmp2);
        }
        #pragma omp taskwait
        *res = tmp1 + tmp2;
	}
}

int main(int argc, char *argv[]) {
    if( argc < 2 ) {
        printf("usage: %s n\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
	int res;
	double start = omp_get_wtime();
	synthetic(n, &res);
	#pragma omp taskwait
	double end = omp_get_wtime();
	printf("synthetic(%d): %d, time, %f\n",n, res, end - start);
}
