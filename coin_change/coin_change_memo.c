#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int *memo;
int ori_n;

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
    int aux1=0, aux2=0;
    if(memo[value*(ori_n+1)+coins_size-1] == -1) {
        count(coins, coins_size-1, value, &aux1);
        memo[value*(ori_n+1)+coins_size-1] = aux1;
    }
    if(value-coins[coins_size-1] >= 0) {
        if(memo[(value-coins[coins_size-1])*(ori_n+1)+coins_size] == -1) {
            count(coins, coins_size, value-coins[coins_size-1], &aux2);
            memo[(value-coins[coins_size-1])*(ori_n+1)+coins_size] = aux2;
        }
        *res = memo[value*(ori_n+1)+coins_size-1]+memo[(value-coins[coins_size-1])*(ori_n+1)+coins_size];
    }
    else {
        *res = memo[value*(ori_n+1)+coins_size-1];
    }
}

// Driver program to test above function
int main(int argc, char *argv[]) {
	const char *filename;
	int n, i, value;
	
	if(argc!=4) {
		printf("./%s filename size value\n", argv[0]);
		exit(0);
	}

    filename = argv[1];
    n = atoi(argv[2]);
    ori_n = n;
    value = atoi(argv[3]);
    memo = calloc((value+1)*(n+1), sizeof(int));
    memset(memo, -1, (value+1)*(n+1)*sizeof(int));
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
