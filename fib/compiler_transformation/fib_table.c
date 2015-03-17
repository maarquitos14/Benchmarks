#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/mman.h>
#include <assert.h>

int *memo;
 
int fib(int n) {
	if(n<2) return n;
	else {
        __assume_aligned(memo, 64);
        if(memo[n-1]==0) memo[n-1] = fib(n-1);

        if(memo[n-2]==0) memo[n-2] = fib(n-2);

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
    int max = ( n > m ? n : m );

    struct timespec tstart, tend;
    clock_gettime( CLOCK_REALTIME, &tstart );
    memo = (int *) mmap( NULL, max*sizeof(int), PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_NONBLOCK, -1, 0 );
    assert( memo != MAP_FAILED );
    const int ret = madvise( (void *) memo, max*sizeof(int), MADV_SEQUENTIAL );
    assert( ret == 0 );
    int res = fib(n);
    int res2 = fib(m);
    clock_gettime( CLOCK_REALTIME, &tend );

    printf( "res=%d, res2=%d\n", res, res2 );
    printf( "Time %f\n", (double) ( tend.tv_sec - tstart.tv_sec ) + ( tend.tv_nsec - tstart.tv_nsec )/1E9 ); 
}
