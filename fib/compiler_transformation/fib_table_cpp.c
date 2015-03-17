#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


int fib(int n) {
	if(n<2) return n;
    else {
        int n1 = get_element( n-1 );
        if (n1 == -1) {
            n1 = fib(n-1);
            set_element( n-1, n1 );
        }

        int n2 = get_element( n-2 );
        if (n2 == -1) {
            n2 = fib(n-2);
            set_element( n-2, n2 );
        }

        return n1 + n2;
    }
}

int main(int argc, char *argv[]) {
    if( argc < 3 ) {
        printf("Usage: %s n m\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
    int m = atoi(argv[2]);


    struct timespec tstart, tend;
    clock_gettime( CLOCK_REALTIME, &tstart );
    init(m*sizeof(int));
    int res = fib(n);
    int res2 = fib(m);
    clock_t end = clock();
    clock_gettime( CLOCK_REALTIME, &tend );

    printf( "res=%d, res2=%d\n", res, res2 );
    printf( "Time %f\n", (double) ( tend.tv_sec - tstart.tv_sec ) + ( tend.tv_nsec - tstart.tv_nsec )/1E9 ); 
}
