#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/mman.h>
#include <assert.h>
 
int *memo;
int capacity = 4000;
//int capacity = 400;
//int capacity = 40;

typedef struct {
	int weight, value;
} item_t;

int optimal(int weight, int idx, const item_t item[]) {
	if (idx < 0) {
		return 0;
	}
 
    __assume_aligned(memo, 64);
    if (weight < item[idx].weight) {
        if( idx - 1 >= 0 ) {
            if( memo[(idx-1) * (capacity+1) + weight] == 0 ) {
                memo[(idx-1) * (capacity+1) + weight] = optimal(weight, idx-1, item); 
            }
            return memo[(idx-1) * (capacity+1) + weight];
        }
        return 0;
    }
	
    if( idx - 1 >= 0 ) {
        if( memo[(idx-1) * (capacity+1) + weight] == 0 ) {
            memo[(idx-1) * (capacity+1) + weight] = optimal(weight, idx-1, item);
        }
        if( weight - item[idx].weight >= 0 ) {
            if( memo[(idx-1) * (capacity+1) + (weight - item[idx].weight)] == 0 ) {
                memo[(idx-1) * (capacity+1) + (weight - item[idx].weight)] = optimal(weight - item[idx].weight, idx-1, item);
            }
            int aux = ( memo[(idx-1) * (capacity+1) + weight] >= ( memo[(idx-1) * (capacity+1) + (weight - item[idx].weight)] + item[idx].value ) ) ?
                memo[(idx-1) * (capacity+1) + weight] : ( memo[(idx-1) * (capacity+1) + (weight - item[idx].weight)] + item[idx].value );
            return aux;
        }
        else {
            return ( memo[(idx-1) * (capacity+1) + weight] >= item[idx].value ) ? memo[(idx-1) * (capacity+1) + weight] : item[idx].value;
        }
    }
	return item[idx].value;
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

    struct timespec tstart, tend;
    clock_gettime( CLOCK_REALTIME, &tstart );
    memo = (int *) mmap( NULL, max*(capacity+1)*sizeof(int), PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_NONBLOCK, -1, 0 );
    assert( memo != MAP_FAILED );
    const int ret = madvise( (void *) memo, max*(capacity+1)*sizeof(int), MADV_SEQUENTIAL );
    assert( ret == 0 );
	int res = optimal(capacity, n-1, item);
	int res2 = optimal(capacity, m-1, item);
    clock_gettime( CLOCK_REALTIME, &tend );

    printf( "res=%d, res2=%d\n", res, res2 );
    printf( "Time %f\n", (double) ( tend.tv_sec - tstart.tv_sec ) + ( tend.tv_nsec - tstart.tv_nsec )/1E9 ); 
}

