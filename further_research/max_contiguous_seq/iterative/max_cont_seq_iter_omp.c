#include <stdio.h>
#include <omp.h>
 
typedef struct Range {
    int start, end, sum;
} Range;
 
void maxSubseq(const int sequence[], const int len, Range *res) {
    int maxSum=0, thisSum = 0, i = 0;
    int start = 0, end = -1, j;
 
	#pragma omp for shared(maxSum, thisSum, i, start, end)
    for (j = 0; j < len; j++) {
		#pragma omp atomic
		thisSum += sequence[j];
		if (thisSum < 0) {
			#pragma omp atomic
			i = j + 1;
			#pragma omp atomic
			thisSum = 0;
		} else if (thisSum > maxSum) {
			#pragma omp critical
			{	
				printf("thisSum %d maxSum %d\n", thisSum, maxSum);
				maxSum = thisSum;
				start = i;
				end   = j;
			}
		}
    }
	
    if (start <= end && start >= 0 && end >= 0) {
        res->start = start;
        res->end = end + 1;
        res->sum = maxSum;
    } else {
        res->start = 0;
        res->end = 0;
        res->sum = 0;
    }
}
 
int main(int argc, char **argv) {
	int seqlength;
	const char *filename;
	int i;
	Range res;
	
	if(argc==3) {
		filename = argv[1];
		seqlength = atoi(argv[2]);
	}
	else {
		printf("./max_cont_seq_iter filename size\n");
		exit(0);
	}

	int seq[seqlength]
	FILE *f = fopen(filename, "r");
	for(i=0;i<seqlength;i++)
		fscanf(f, "%d", &seq[i]);
 
	double start = omp_get_wtime();
    maxSubseq(seq, seqlength, &res);
    double end = omp_get_wtime();
    printf("Max sum = %d\n", res.sum);
    printf("Start %d End %d\n", res.start, res.end);
    /*for (i = res.start; i < res.end; i++)
        printf("%d ", seq[i]);
    printf("\n");*/
 
	printf("time %f\n", end - start);
    return 0;
}
