#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <string.h>

int ori_n;
int *memo;
 
void fib(int n, int *res) {
	if(n<2) *res = n;
	else
	{
		int res1, res2;
        if(memo[n-1]==-1) {
		    fib(n-1, &res1);
            memo[n-1] = res1;
        }
        if(memo[n-2]==-1) {
		    fib(n-2, &res2);
            memo[n-2] = res2;
        }
		*res = memo[n-1] + memo[n-2];
	}
}

int main(int argc, char *argv[]) {
    if( argc < 2 ) {
        printf("Usage: %s n\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
	ori_n = n;
    memo = calloc(n, sizeof(int));
    memset(memo, -1, n*sizeof(int));
	int res;
	double start = omp_get_wtime();
	fib(n, &res);
	double end = omp_get_wtime();
	printf("fib(%d): %d, time, %f\n",n, res, end - start);
}
