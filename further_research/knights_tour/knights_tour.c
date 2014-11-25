#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "omp.h"

typedef struct
{
    int x, y;
} move_t;

typedef struct sol_node
{
    move_t pos;
    struct sol_node* prev;
} sol_node_t;


int visited_position(move_t m, sol_node_t* sol)
{
    sol_node_t* aux = sol;
    while (aux != 0)
    {
        if (aux->pos.x == m.x && aux->pos.y == m.y)
            return 1;

        aux = aux->prev;
    }
    return 0;
}


move_t vector_add (move_t *a, move_t *b)
{
    move_t c;
    c.x = a->x + b->x;
    c.y = a->y + b->y;
    return c;
}

move_t moves[8]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};

int N;

int findtour(int move_num, move_t m, sol_node_t sol)
{
    //check final position
    if(move_num == (N*N))
    {
        return 1;
    }

    //test all new possible moves
    int i, sum = 0;
    for(i = 0; i < 8; i++)
    {
        if (move_num < 4)
        {
            //fprintf(stderr, "testing movement: %d\n", i);
        }
        move_t new_move = vector_add(&m, &moves[i]);
        int pos = new_move.y * N + new_move.x;
        if ( !( (new_move.x < 0) || (new_move.x >= N) || (new_move.y < 0) || (new_move.y >= N) ) && !visited_position(new_move, &sol) )
        {
            sol_node_t new_sol;
            new_sol.pos = new_move;
            new_sol.prev = &sol;
            {
                int tmp = findtour(move_num+1, new_move, new_sol);
                sum = sum + tmp;
            }
        }
    }
    return sum;
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("./knights N\n");
        exit(1);
    }

    N = atoi(argv[1]);

    int n_solutions = 0, i;
    double start = omp_get_wtime();
    for (i = 0; i < N*N;++i)
    {
        move_t initial_move = { i % N, i / N};
        sol_node_t initial_sol = { initial_move, 0};
        //fprintf(stderr, "initial_pos: (%d, %d)\n", initial_move.x, initial_move.y);
        n_solutions += findtour(1, initial_move, initial_sol);
        //fprintf(stderr, "%i\n", n_solutions);
    }
    double end = omp_get_wtime();

    fprintf(stderr, "test: %s, time: %.6f, size: %i, result: %d, threads: %i\n", argv[0], end-start, N, n_solutions, omp_get_num_threads());
    return 0;
}
