#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
 
typedef struct {
	int weight, value;
} item_t;

int n;
int final = 0;
int capacity = 400;
//int capacity = 40;

#pragma omp task memo(n, capacity+1, idx, weight) out(*sol) final(idx < n-final || weight < weight/5) 
void optimal(int weight, int idx, int *sol, const item_t item[]) {
	if (idx < 0) {
		*sol=0;
		return;
	}
    else {
        if (weight < item[idx].weight) {
            if(idx - 1 >= 0) {
                optimal(weight, idx - 1, sol, item);
                #pragma omp taskwait
            }
            return;
        }

        int v1=0, v2=0;
        if(idx - 1 >= 0) {
            optimal(weight, idx - 1, &v1, item);
            if(weight-item[idx].weight >= 0) {
                optimal(weight - item[idx].weight, idx - 1, &v2, item);
            }
        }
        #pragma omp taskwait
        v2 += item[idx].value;
        *sol = (v1>=v2) ? v1 : v2;
    }
}
 
int main(int argc, char *argv[]) {
	const char *filename;
	int i;
	
	if(argc<3) {
		printf("./%s filename size\n", argv[0]);
		exit(0);
	}

    filename = argv[1];
    n = atoi(argv[2]);
    final = n;
    if(argc == 4) {
        final = atoi(argv[3]);
    }
	item_t item[n];
	FILE *f = fopen(filename, "r");
	for(i=0;i<n;i++)
		fscanf(f, "%d,%d", &item[i].weight, &item[i].value);
//	for(i=0;i<n;i++)
//		printf("weight %d value %d\n", item[i].weight, item[i].value);
	int sol = 0;
	double start = omp_get_wtime();
	optimal(capacity, n-1, &sol, item);
	#pragma omp taskwait
	double end = omp_get_wtime();

	printf("Total value: %d\n", sol);
	printf("Time: %f\n", end-start);
	return 0;
}
