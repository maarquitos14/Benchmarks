#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <tr1/unordered_map>
#include <string.h>

int ori_n;
int final = 0;

#pragma omp task memo(n+1,n) out(*res) final(1)//final(n < ori_n - final) label(fib1) copy_deps
void fib(int n, int *res) {
	if(n<2) *res = n;
	else
	{
		int res1 = 0, res2 = 0;
		fib(n-1, &res1);
		fib(n-2, &res2);
		#pragma omp taskwait
		*res = res1 + res2;
	}
}


int main(int argc, char *argv[]) {
    if( argc < 2 ) {
        printf("usage: %s n\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
    if( argc == 3) {
        final = atoi(argv[2]);
    }
	ori_n = n;
	int res = 0;
	double start = omp_get_wtime();
	fib(n, &res);
	#pragma omp taskwait
	double end = omp_get_wtime();
	printf("fib(%d): %d, time, %f\n",n, res, end - start);
}
