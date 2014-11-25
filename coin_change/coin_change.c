#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Returns the count of ways we can sum  coins[0...m-1] coins to get sum value
void count(int * coins, int coins_size, int value, int *res) {
    // If value is 0 then there is 1 solution (do not include any coin)
    if (value == 0) {
        *res = 1;
        return;
    }
    // If value is less than 0 then no solution exists
    if (value < 0) {
        *res = 0;
        return;
    }
    // If there are no coins and value is greater than 0, then no solution exist
    if (coins_size <=0 && value >= 1) {
        *res = 0;
        return;
    }
    // count is sum of solutions (i) including coins[coins_size-1] (ii) excluding coins[coins_size-1]
    int aux1, aux2;
    count(coins, coins_size-1, value, &aux1);
    count(coins, coins_size, value-coins[coins_size-1], &aux2);
    *res = aux1+aux2;
}

// Driver program to test above function
int main(int argc, char *argv[]) {
	const char *filename;
	int n, i, value;
	
	if(argc==4) {
		filename = argv[1];
		n = atoi(argv[2]);
        value = atoi(argv[3]);
	}
	else {
		printf("./%s filename size value\n", argv[0]);
		exit(0);
	}

	int coins[n];
	FILE *f = fopen(filename, "r");
	for(i=0;i<n;i++)
		fscanf(f, "%d", &coins[i]);
    int res;
    double start = omp_get_wtime();
    count(coins, n, value, &res);
    double end = omp_get_wtime();
    printf("%d\n", res);
    printf("time %f\n", end-start);
    return 0;
}
