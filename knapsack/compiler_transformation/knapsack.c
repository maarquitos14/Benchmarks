#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
 
typedef struct {
	int weight, value;
} item_t;

int capacity=4000;

#pragma memo transform index(idx, weight)
void optimal(int weight, int idx, int *sol, const item_t item[]) {
	int v1, v2;
	if (idx < 0) {
		*sol=0;
		return;
	}
 
	if (weight < item[idx].weight) {
		optimal(weight, idx - 1, sol, item);
		return;
	 }
	
	optimal(weight, idx - 1, &v1, item);
	optimal(weight - item[idx].weight, idx - 1, &v2, item);
	
	v2 += item[idx].value;
 
	*sol = (v1>=v2) ? v1 : v2;
}
 
int main(int argc, char *argv[]) {
	int i;
	
	if( argc < 4 ) {
		printf("./%s filename n m\n", argv[0]);
		exit(0);
	}

    const char *filename = argv[1];
    int n = atoi(argv[2]);
    int m = atoi(argv[3]);
    int max = ( n > m ? n : m );

	item_t item[max];
	FILE *f = fopen(filename, "r");
	for(i=0;i<max;i++)
		fscanf(f, "%d,%d", &item[i].weight, &item[i].value);
    #pragma memo sparse function(optimal) size(n) init(-1)
	int res = optimal(capacity, n-1, item);
	int res2 = optimal(capacity, m-1, item);

    printf( "res=%d, res2=%d\n", res, res2 );
    printf( "Time %f\n", (double) (end - begin)/CLOCKS_PER_SEC ); 
}
