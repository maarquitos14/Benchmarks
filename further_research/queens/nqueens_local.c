#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "omp.h"

typedef struct sol_node
{
    int col;
    struct sol_node * prev;
} sol_node_t, *sol_t;

static inline int check_attack(const int col, const int i, sol_t sol)
{
    int j;
    for (j = 0; j < col; j++)
    {
        const int tmp = abs(sol->col - i);
        if(tmp == 0 || tmp == j+1)
            return 1;
        sol = sol->prev;
    }
    return  0;
}

int final_depth;
int solve(int n, const int col, sol_node_t sol)
{
    if (col == n)
    {
        return 1;
    }

    int i, result = 0;
    for (i = 0; i < n; i++)
    {
        if (!check_attack(col, i, &sol))
        {
            sol_node_t new_sol;
            new_sol.prev = &sol;
            new_sol.col = i;

            //#pragma omp task final(final_depth <= col) reduction(+: result)
            #pragma omp task final(final_depth <= col) commutative(result) memo(n, col) out(result)
            {
                //smateo: Do not merge these two statements
                int tmp = solve(n, col + 1, new_sol);
                result += tmp;
            }
        }
    }

 #pragma omp taskwait
     //printf("Res %d\n", result);
     return result;
}

int main(int argc, char **argv)
{

    if(argc != 3)
    {
        printf("./nqueens n final_depth\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    final_depth = atoi(argv[2]);

    assert(n > 0);

    sol_node_t initial_node = {-1, 0};
    //timer_start(0);
    double start = omp_get_wtime();
    int count_main = solve(n, 0, initial_node);
    double end = omp_get_wtime();
    //timer_stop(0);

#ifdef VERBOSE
    printf("Total solutions for %d x %d: %d\n", n, n, count_main);
#else
    printf("test: %s, time: %.6f, size: %i, result: %d, threads: %i, final: %i\n", argv[0], end-start, n, count_main, omp_get_num_threads(), final_depth);
#endif
    return 0;
}
