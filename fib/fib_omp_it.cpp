#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int ori_n;
int final = 0;

//#pragma omp task memo(n+1,n) out(*res) final(n < ori_n - final) label(fib1)
void fib(int n, int *res) {
	if(n<2) *res = n;
	else
	{
		int res1, res2;
		fib(n-1, &res1);
		fib(n-2, &res2);
		#pragma omp taskwait
		*res = res1 + res2;
	}
}


//#pragma omp task memo(n+1,n) out(*res) final(n < ori_n - final) label(fib2)
void fib2(int n, int *res) {
	if(n<2) *res = n;
	else
	{
		int res1, res2;
		fib2(n-1, &res1);
		fib2(n-2, &res2);
		#pragma omp taskwait
		*res = res1 + res2;
	}
}

int main(int argc, char *argv[]) {
    if( argc < 2 ) {
        printf("usage: %s n\n", argv[0]);
        exit(0);
    }
	int n = atoi(argv[1]);
    if( argc == 3) {
        final = atoi(argv[2]);
    }
	ori_n = n;
	int res, res2;
	double start = omp_get_wtime();
	//fib(n, &res);
    //fib2(n, &res2);

    int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    // arr
     for (int i = 2; i <= n; ++i)
    {
        //#pragma omp task in(arr[i-1], arr[i-2]) out(arr[i])
        #pragma omp task shared(arr) 
        {
            arr[i] = arr[i-1] + arr[i-2];
        }
	    #pragma omp taskwait
     }
	//#pragma omp taskwait
    res = arr[n];

	double end = omp_get_wtime();
	printf("fib(%d): %d, time, %f\n",n, res, end - start);
	//printf("fib2(%d): %d, time, %f\n",n, res2, end - start);
}
