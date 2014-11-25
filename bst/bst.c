#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void bst(int n, long int * res) {
    int i;
    if(n<2) *res = 1;
    else {
        for(i=0;i<n;i++) {
            long int aux1 = 0, aux2 = 0;
            bst(i, &aux1);
            bst(n-i-1, &aux2);
            *res += aux1*aux2;
        }
    }
}

int main (int argc, char *argv[]) {
    int n;
    if(argc!=2) {
        printf("Usage: %s n\n", argv[0]);
        exit(0);
    }
    n = atoi(argv[1]);
    long int res = 0;
    double start = omp_get_wtime();
    bst(n, &res);
    double end = omp_get_wtime();
    printf("bst(%d) = %ld, time %f\n", n, res, end-start);
}
