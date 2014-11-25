#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int ori_n;
int final = 0;

#pragma omp task memo(value+1, coins_size+1, value, coins_size) out(*res)
void count(int * coins, int coins_size, int value, int *res) {
    if (value == 0) {
        *res = 1;
        return;
    }
    if (value < 0) {
        *res = 0;
        return;
    }
    if (coins_size <=0) {
        *res = 0;
        return;
    }
    int aux1 = 0, aux2 = 0;
    count(coins, coins_size-1, value, &aux1);
    if(value-coins[coins_size-1] >= 0) {
        count(coins, coins_size, value-coins[coins_size-1], &aux2);
    }
    #pragma omp taskwait
    *res = aux1+aux2;
}

int main(int argc, char *argv[]) {
	const char *filename;
	int n, i, value;
	
	if(argc < 4) {
		printf("./%s filename size value\n", argv[0]);
		exit(0);
	}

    filename = argv[1];
    n = atoi(argv[2]);
    ori_n = n;
    value = atoi(argv[3]);
    if(argc == 5) {
        final = atoi(argv[4]);
    }
	int coins[n];
	FILE *f = fopen(filename, "r");
	for(i=0;i<n;i++)
		fscanf(f, "%d", &coins[i]);
    int res;
    double start = omp_get_wtime();
    count(coins, n, value, &res);
    #pragma omp taskwait
    double end = omp_get_wtime();
    printf("%d\n", res);
    printf("time %f\n", end-start);
    return 0;
}
