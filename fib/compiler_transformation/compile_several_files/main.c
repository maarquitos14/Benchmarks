#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char *argv[]) {
    //#pragma memo function(fib) size(n) index(n) [init(-1)] 
	int res = fib(20);
    int res2 = foo(15);
    printf( "res=%d, res2=%d\n", res, res2 );
}
