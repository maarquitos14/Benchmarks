#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "omp.h"

typedef struct sol_node {
    int col;
    struct sol_node * prev;
} sol_node_t, *sol_t;

static inline int check_attack(const int col, const int i, sol_t sol) {
    int j;
    
    if (!sol->prev) return 0;

    for (j = 0; j < col; j++) {
        const int tmp = abs(sol->col - i);
        if(tmp == 0 || tmp == j+1)
            return 1;
        sol = sol->prev;
    }
    return  0;
}

int final_depth;
//#pragma omp task final(final_depth <= col) commutative(*result) memo(10, 10, col, sol.col)
#pragma omp task out(*result) memo(n + 1, n + 1, col, sol.col) 
void solve(int n, const int col, int *result, sol_node_t sol) {
    if (col == n) {
        printf("A solution has been found\n");
        *result = 1;
        return;
    }
    int i;
    //int *tmp = calloc(n, 4);
    int tmp[n];
    for (i = 0; i < n; i++) {
        tmp[i] = 0; 
        if (!check_attack(col, i, &sol)) {
            sol_node_t new_sol;
            new_sol.prev = &sol;
            new_sol.col = i;
            solve(n, col + 1, &tmp[i], new_sol);
        }
    }
    #pragma omp taskwait

    int tmp_res = 0;
    for(i=0;i<n;i++) {
    printf("%d ", tmp[i]);
        *result += tmp[i];
    }

    printf("\n");
}


int main(int argc, char **argv) {
    if(argc != 3) {
        printf("./nqueens n final_depth\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    final_depth = atoi(argv[2]);
    assert(n > 0);
    sol_node_t initial_node = {0, 0};
    int result=0;
    double start = omp_get_wtime();
    solve(n, 0, &result, initial_node);
    #pragma omp taskwait
    double end = omp_get_wtime();
#ifdef VERBOSE
    printf("Total solutions for %d x %d: %d\n", n, n, result);
#else
    printf("test: %s, time: %.6f , size: %i, result: %d, threads: %i, final: %i\n", argv[0], end-start, n, result, omp_get_num_threads(), final_depth);
#endif
    return 0;
}
