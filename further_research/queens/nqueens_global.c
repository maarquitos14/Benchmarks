#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "omp.h"

typedef struct sol_node {
    int col;
    struct sol_node * prev;
} sol_node_t, *sol_t;

static inline int check_attack(const int col, const int i, sol_t sol) {
    int j;
    for (j = 0; j < col; j++) {
        const int tmp = abs(sol->col - i);
        if(tmp == 0 || tmp == j+1)
            return 1;
        sol = sol->prev;
    }
    return  0;
}

void solve(int n, const int col, sol_node_t sol, int *result) {
    if (col == n) {
        *result = 1;
        return;
    }
    int i;
    for (i = 0; i < n; i++) {
        if (!check_attack(col, i, &sol)) {
            sol_node_t new_sol;
            new_sol.prev = &sol;
            new_sol.col = i;
            int tmp = 0;
            solve(n, col + 1, new_sol, &tmp);
            *result += tmp;
        }
    }
}

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("./nqueens n\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    assert(n > 0);
    sol_node_t initial_node = {-1, 0};
    int result=0;
    double start = omp_get_wtime();
    solve(n, 0, initial_node, &result);
    double end = omp_get_wtime();
#ifdef VERBOSE
    printf("Total solutions for %d x %d: %d\n", n, n, result);
#else
    printf("test: %s, time: %.6f , size: %i, result: %d, threads: %i\n", argv[0], end-start, n, result, omp_get_num_threads());
#endif
    return 0;
}
