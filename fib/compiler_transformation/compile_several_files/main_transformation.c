#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//We know the type of the table using the return type of the function.
int *table;

int main(int argc, char *argv[]) {
    if( argc < 3 ) {
        printf("Usage: %s n\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    //#pragma memo function(fib) size(n) init(-1) //index(n) 
    //Allocating table with the size give in "size". The type of the table is the return type of the function given in "function".
    table = (int * ) malloc(n*sizeof(int));
    //Initializing table to the value given in "init".
    memset( table, -1, n*sizeof(int) );
    //fib is defined in another file, so we must change the function to pass the table pointer.
    //Without using runtime, just a table per file is possible. This fact means that between fib(20) and foo(15) (which is actually fib(15)), there isn't table-sharing. 
    clock_t begin = clock();
	int res = fib(n);
    //int res = fib(m, table);
    int res2 = foo(m);
    clock_t end = clock();
    printf( "res=%d, res2=%d\n", res, res2 );
    printf( "Time %f\n", (double) (end - begin)/CLOCKS_PER_SEC ); 
}
