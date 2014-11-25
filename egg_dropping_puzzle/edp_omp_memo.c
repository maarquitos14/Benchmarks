#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <limits.h>

int final = 0;
int ori_n, ori_k;

int max(int a, int b) { return (a > b)? a: b; }

#pragma omp task out(*res) memo(n+1, k+1, n, k) final(n < ori_n-final || k < ori_k-final)
void eggDrop(int n, int k, int *res) {
    if (k == 1 || k == 0) {
        *res = k;
        return;
    }

    if (n == 1) {
        *res = k;
        return;
    }

    int min = INT_MAX, x, tmp;
    int aux1[k+1], aux2[k+1];

    for (x = 1; x <= k; x++) {
        eggDrop(n-1, x-1, &aux1[x]);
        eggDrop(n, k-x, &aux2[x]);
    }
    #pragma omp taskwait
    for(x = 1; x <= k; x++) {
        tmp = max(aux1[x], aux2[x]);
        if (tmp < min) {
            min = tmp;
        }
    }
    *res = min+1;
}

int main(int argc, char * argv[]) {
    if(argc < 3) {
        printf("usage: %s eggs floors\n", argv[0]);
        exit(0);
    }
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    ori_n = n;
    ori_k = k;
    if(argc == 4) {
        final = atoi(argv[3]);
    }
    int res = 0;
    double start = omp_get_wtime();
    eggDrop(n, k, &res);
    #pragma omp taskwait
    double end = omp_get_wtime();
    printf("%d, time %f \n", res, end-start);
    return 0;
}
