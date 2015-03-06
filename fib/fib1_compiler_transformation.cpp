#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <string.h>

int*table_fib;

int fib(int n) {
	if(n<2) return n;
    else {
        if (table_fib[n-1] == -1) table_fib[n-1] = fib(n-1);
        //if (__builtin_expect(table_fib[n-1] == -1, 0)) table_fib[n-1] = fib(n-1);
        if (table_fib[n-2] == -1) table_fib[n-2] = fib(n-2);
        //if (__builtin_expect(table_fib[n-2] == -1, 0)) table_fib[n-2] = fib(n-2);
        return table_fib[n-1] + table_fib[n-2];
    }
}

int main(int argc, char *argv[]) {
    if( argc < 2 ) {
        printf("Usage: %s n\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
	int res;
    //#pragma memo function(fib) size(n) //falta el indice
    table_fib = (int*) calloc(n+1, sizeof(int));
    memset(table_fib, -1, (n+1)*sizeof(int));
	double start = omp_get_wtime();
    if (table_fib[n] == -1) table_fib[n] = fib(n);
    res = table_fib[n];        
    double end = omp_get_wtime();
	//printf("fib(%d): %d, time, %f\n",n, res, end - start);
    printf("%f\n", end-start); 
}
