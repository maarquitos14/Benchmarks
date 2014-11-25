#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <limits.h>
#include <string.h>

int *memo;
int ori_k;

int max(int a, int b) { return (a > b)? a: b; }

/* Function to get minimum number of trails needed in worst
   case with n eggs and k floors */
void eggDrop(int n, int k, int *res) {
    // If there are no floors, then no trials needed. OR if there is
    // one floor, one trial needed.
    if (k == 1 || k == 0) {
        *res = k;
        return;
    }

    // We need k trials for one egg and k floors
    if (n == 1) {
        *res = k;
        return;
    }

    int min = INT_MAX, x, tmp;

    // Consider all droppings from 1st floor to kth floor and
    // return the minimum of these values plus 1.
    for (x = 1; x <= k; x++) {
        int aux1, aux2;
        if(memo[(n-1)*ori_k+(x-1)] == -1) {
            eggDrop(n-1, x-1, &aux1);
            memo[(n-1)*ori_k+(x-1)] = aux1;
        }
        if(memo[n*ori_k+(k-x)] == -1) {
            eggDrop(n, k-x, &aux2);
            memo[n*ori_k+(k-x)] = aux2;
        }
        tmp = max(memo[(n-1)*ori_k+(x-1)], memo[n*ori_k+(k-x)]);
        if (tmp < min) {
            min = tmp;
        }
    }
    *res = min+1;
}

/* Driver program to test to pront printDups*/
int main(int argc, char * argv[]) {
    if(argc != 3) {
        printf("usage: %s eggs floors\n", argv[0]);
        exit(0);
    }
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    ori_k = k;
    memo = calloc((n+1)*(k+1), sizeof(int));
    memset(memo, -1, (n+1)*(k+1)*sizeof(int));
    int res = 0;
    double start = omp_get_wtime();
    eggDrop(n, k, &res);
    double end = omp_get_wtime();
    printf("%d, time %f \n", res, end-start);
    return 0;
}
