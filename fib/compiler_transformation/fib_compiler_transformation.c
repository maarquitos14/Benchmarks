#include<stdio.h>
#include<stdlib.h>

#pragma memo transform index(n)
int fib(int n)
{
	if(n<2) return n;
    else return fib(n-1)+fib(n-2);
}


int main(int argc, char *argv[]) {
    if( argc < 3 ) {
        printf("Usage: %s n\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
    int m = atoi(argv[2]);
	int res, res2;
    #pragma memo function(fib) size(n) init(-1)
	res = fib(n);
    res2 = fib(m);
	printf("fib(%d): %d\n",n, res);
}
