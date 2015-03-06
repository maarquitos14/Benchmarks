
int ori_n;
int N = 100;
 

int fib(int n)
{
	if(n<2) return n;
    else
        return fib(n-1)+fib(n-2);
}


int main(int argc, char *argv[]) {
    if( argc < 2 ) {
        printf("Usage: %s n\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
	ori_n = n;
	int res;
	double start = omp_get_wtime();
    
    #pragma memo function(fib) size(n) //falta el indice

	fib(n, &res);

	fib(n, &res);
	double end = omp_get_wtime();
	printf("fib(%d): %d, time, %f\n",n, res, end - start);
}
