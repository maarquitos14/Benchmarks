#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <string.h>

int *memo;
 
int fib(int n) {
	if(n<2) return n;
	else {
        if(memo[n-1]==-1) memo[n-1] = fib(n-1);
        if(memo[n-2]==-1) memo[n-2] = fib(n-2);
		return memo[n-1] + memo[n-2];
	}
}

int main(int argc, char *argv[]) {
    if( argc < 2 ) {
        printf("Usage: %s n\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
    memo = calloc(n+1, sizeof(int));
    memset(memo, -1, (n+1)*sizeof(int));
	int res;
	double start = omp_get_wtime();
    if (memo[n] == -1) memo[n] = fib(n);
    res = memo[n];        
	double end = omp_get_wtime();
	//printf("fib(%d): %d, time, %f\n",n, res, end - start);
    printf("%f\n", end-start); 
}
