#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int ori_n;
int final;

#pragma omp task out(*res) final(n < ori_n - final) 
void bst(int n, long int * res) {
    int i;
    if(n<2) *res = 1;
    else {
	    long int tmp1[n];
	    long int tmp2[n];
	    memset(tmp1, 0, n*sizeof(long int));
	    memset(tmp2, 0, n*sizeof(long int));
	    for(i=0;i<n;i++) {
		    bst(i, &tmp1[i]);
		    bst(n-i-1, &tmp2[i]);
	    }
	    #pragma omp taskwait
	    for(i=0;i<n;i++) {
		    *res += tmp1[i]*tmp2[i];
	    }
    }
}

int main (int argc, char *argv[]) {
    int n;
    if(argc!=3) {
        printf("Usage: %s n final\n", argv[0]);
        exit(0);
    }
    n = atoi(argv[1]);
    ori_n = n;
    final = atoi(argv[2]);
    long int res = 0;
    double start = omp_get_wtime();
    bst(n, &res);
    #pragma omp taskwait
    double end = omp_get_wtime();
    printf("bst(%d) = %ld, time %f\n", n, res, end-start);
}
