#include<stdlib.h>
#include<string.h>

extern int *table;
int foo( int n ) {
    //#pragma memo function(fib) size(n) init(-1) //index(n) 
    //table = (int * ) malloc(n*sizeof(int));
    //memset( table, -1, n*sizeof(int) );
    //fib is defined in another file, so we must change the function to pass the table pointer.
    return fib(n);
    //return fib(n, table);
}
