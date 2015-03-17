#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

int *memo;
 
int fib(int n) {
	if(n<2) return n;
	else {
        __assume_aligned(memo, 64);
        if(memo[n-1]==-1) memo[n-1] = fib(n-1);

        if(memo[n-2]==-1) memo[n-2] = fib(n-2);

		return memo[n-1] + memo[n-2];
	}
}

int main(int argc, char *argv[]) {
    if( argc < 3 ) {
        printf("Usage: %s n m\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
    int max = n > m ? n : m;

    struct timespec tstart, tend;
    clock_gettime( CLOCK_REALTIME, &tstart );
    memo = (int *) _mm_malloc(max*sizeof(int), 64);
    assert( memo != NULL );
    __assume_aligned(memo, 64);
    memset(memo, -1, max*sizeof(int));
    assert( memo != NULL );
    int res = fib(n);
    int res2 = fib(m);
    clock_gettime( CLOCK_REALTIME, &tend );

    _mm_free(memo);
    printf( "res=%d, res2=%d\n", res, res2 );
    printf( "Time %f\n", (double) ( tend.tv_sec - tstart.tv_sec ) + ( tend.tv_nsec - tstart.tv_nsec )/1E9 ); 
}
