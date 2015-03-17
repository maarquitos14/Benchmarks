#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
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
 
    //TODO:FIXME: Think about this part, I think it is not consulting table before computing.
    if (weight < item[idx].weight) {
        if( idx - 1 >= 0 ) {
            int aux = get_element( (idx-1)*(capacity+1)+weight );
            if( aux == -1 ) {
                aux = optimal(weight, idx-1, item); 
                set_element( (idx-1)*(capacity+1)+weight, aux );
            }
            return aux; 
        }
        return 0;
    }
	
    if( idx - 1 >= 0 ) {
        int aux = get_element( (idx-1)*(capacity+1)+weight );
        if( aux == -1 ) {
            aux = optimal(weight, idx-1, item); 
            set_element( (idx-1)*(capacity+1)+weight, aux );
        }
        if( weight - item[idx].weight >= 0 ) {
            int aux2 = get_element( (idx-1)*(capacity+1)+(weight - item[idx].weight) );
            if( aux2 == -1 ) {
                aux2 = optimal(weight - item[idx].weight, idx-1, item); 
                set_element( (idx-1)*(capacity+1)+(weight - item[idx].weight), aux2);
            }
            return aux >= aux2+item[idx].value ? aux : aux2+item[idx].value;
        }
        else {
            return aux >= item[idx].value ? aux : item[idx].value;
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
    init( max*(capacity+1) );
	int res = optimal(capacity, n-1, item);
	int res2 = optimal(capacity, m-1, item);
    clock_gettime( CLOCK_REALTIME, &tend );

    //destroy();
    printf( "res=%d, res2=%d\n", res, res2 );
    printf( "Time %f\n", (double) ( tend.tv_sec - tstart.tv_sec ) + ( tend.tv_nsec - tstart.tv_nsec )/1E9 ); 
}

