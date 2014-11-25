#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
 
typedef struct {
	int weight, value;
} item_t;

void optimal(int weight, int idx, item_t *sol, const item_t item[]) {
	item_t g[idx+1][weight+1];
	int c, i;
	for(c=0;c<=weight;c++) {
		g[0][c].weight=0;
        g[0][c].value=0;
	}
	for(i=1;i<=idx;i++) {
		g[i][0].weight=0;
        g[i][0].value=0;
	}
	for(i=1;i<=idx;i++) {
		#pragma omp task in(g[i-1]) out(g[i])
		{
            //item_t aux_sol;
            for(c=1;c<=weight;c++) {
                if(c<item[i-1].weight) {    //item weighs more than free cap
                    g[i][c]=g[i-1][c];
                }
                else {  //item fits in knapsack
                    if(g[i-1][c].value > g[i-1][c-item[i-1].weight].value + item[i-1].value) {  //item does not incremente value
                        g[i][c]=g[i-1][c];
                    }
                    else {
                        if(g[i-1][c].value < g[i-1][c-item[i-1].weight].value + item[i-1].value) {
                            g[i][c].value=g[i-1][c-item[i-1].weight].value + item[i-1].value;
                            g[i][c].weight=g[i-1][c-item[i-1].weight].weight + item[i-1].weight;
                        }
                        else {  //same value -> the lightest 
                            g[i][c].value=g[i-1][c].value;
                            if(g[i-1][c].weight <= g[i-1][c-item[i-1].weight].weight + item[i-1].weight) {
                                g[i][c].weight = g[i-1][c].weight;
                            }
                            else {
                                g[i][c].weight = g[i-1][c-item[i-1].weight].weight + item[i-1].weight;
                            }
                        }
                    }
                    //aux_sol=g[i][c];
                }
            }   
            #pragma omp atomic
            *sol = g[idx][weight];
		}
	}
	#pragma omp taskwait
    printf("Last computed: w %d, v %d\n", g[idx][weight].weight, g[idx][weight].value);
}

int main(int argc, char *argv[]) {
	const char *filename;
	int n, i;
	
	if(argc==3) {
		filename = argv[1];
		n = atoi(argv[2]);
	}
	else {
		printf("./max_cont_seq_iter filename size\n");
		exit(0);
	}

	item_t item[n];
	FILE *f = fopen(filename, "r");
	for(i=0;i<n;i++)
		fscanf(f, "%d,%d", &item[i].weight, &item[i].value);
	/*for(i=0;i<n;i++)
		printf("weight %d value %d\n", item[i].weight, item[i].value);*/
	item_t sol;
    sol.value=0;
    sol.weight=0;
	double start = omp_get_wtime();
	optimal(400, n, &sol, item);
	double end = omp_get_wtime();

	printf("Total value: %d, total weight: %d\n", sol.value, sol.weight);
	printf("Time: %f\n", end-start);
	return 0;
}
