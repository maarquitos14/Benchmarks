#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
 
int *memo;
int capacity = 400;
//int capacity = 40;

typedef struct {
	int weight, value;
} item_t;

void optimal(int weight, int idx, int *sol, const item_t item[]) {
	if (idx < 0) {
		*sol=0;
		return;
	}
 
	if (weight < item[idx].weight) {
        optimal(weight, idx - 1, sol, item);
        if( idx - 1 >= 0 ) {
            if( memo[(idx-1) * (capacity+1) + weight] == -1 ) {
                memo[(idx-1) * (capacity+1) + weight] = *sol;
            }
        }
		return;
	 }
	
	int v1 = 0, v2 = 0;
    if( idx - 1 >= 0 ) {
        if( memo[(idx-1) * (capacity+1) + weight] == -1 ) {
            optimal(weight, idx - 1, &v1, item);
            memo[(idx-1) * (capacity+1) + weight] = v1;
        }
        if( weight - item[idx].weight >= 0 ) {
            if( memo[(idx-1) * (capacity+1) + (weight - item[idx].weight)] == -1 ) {
                optimal(weight - item[idx].weight, idx - 1, &v2, item);
                memo[(idx-1) * (capacity+1) + (weight - item[idx].weight)] = v2;
            }
            *sol = ( memo[(idx-1) * (capacity+1) + weight] >= ( memo[(idx-1) * (capacity+1) + (weight - item[idx].weight)] + item[idx].value ) ) ?
                memo[(idx-1) * (capacity+1) + weight] : ( memo[(idx-1) * (capacity+1) + (weight - item[idx].weight)] + item[idx].value );
            return;
        }
        else {
            *sol = ( memo[(idx-1) * (capacity+1) + weight] >= item[idx].value ) ? memo[(idx-1) * (capacity+1) + weight] : item[idx].value;
            return;
        }
    }
	*sol = item[idx].value;
}
 
int main(int argc, char *argv[]) {
	int i;
	
	if( argc != 3 ) {
		printf("./%s filename size\n", argv[0]);
		exit(0);
	}

    const char *filename = argv[1];
    int n = atoi(argv[2]);
    memo = calloc(n * (capacity+1), sizeof(int)); 
    memset(memo, -1, n * (capacity+1) * sizeof(int));

	item_t item[n];
	FILE *f = fopen(filename, "r");
	for(i=0;i<n;i++)
		fscanf(f, "%d,%d", &item[i].weight, &item[i].value);
	/*for(i=0;i<n;i++)
		printf("weight %d value %d\n", item[i].weight, item[i].value);*/
	int sol = 0;;
	double start = omp_get_wtime();
	optimal(capacity, n-1, &sol, item);
	double end = omp_get_wtime();

	printf("Total value: %d\n", sol);
	printf("Time: %f\n", end-start);
	return 0;
}

