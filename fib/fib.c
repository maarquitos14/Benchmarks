#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int ori_n;
int N = 100;
 
void fib(int n, int *res) {
	if(n<2) *res = n;
	else
	{
		int res1, res2;
		fib(n-1, &res1);
		fib(n-2, &res2);
		*res = res1 + res2;
	}
}

int main(int argc, char *argv[]) {
    if( argc < 2 ) {
        printf("Usage: %s n\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
	ori_n = n;
	int res;
	double start = omp_get_wtime();
	fib(n, &res);
	double end = omp_get_wtime();
	printf("fib(%d): %d, time, %f\n",n, res, end - start);
}
