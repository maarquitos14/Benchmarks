#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
 
typedef struct Range {
    int start, end, sum;
} Range;

int seqlength;

void maxSubseq_serial(int current, const int seq[], const int n, Range *res) {
	//printf("current %d len %d\n", current, n);
	if(current!=n) {
		res->start=current;
		res->end=n;
		int i;
		if(seq[current]>0)
			for(i=current;i<n;i++)
				res->sum+=seq[i];
		Range r1, r2, max;
		r1.start=current+1; r2.start=current;
		r1.end=n; r2.end=n-1;
		r1.sum=r2.sum=0;
		maxSubseq_serial(current+1, seq, n, &r1);
		if(seq[current]>0)
			maxSubseq_serial(current, seq, n-1, &r2);
		#pragma omp taskwait
		//printf("res {%d:%d,%d} r1 {%d:%d,%d} r2 {%d:%d,%d}\n", res->start, res->end, res->sum, r1.start, r1.end, r1.sum, r2.start, r2.end, r2.sum);
		if(r1.sum>r2.sum) {
			max.start = r1.start;
			max.end = r1.end;
			max.sum = r1.sum;
		} else if (r2.sum>r1.sum) {
			max.start = r2.start;
			max.end = r2.end;
			max.sum = r2.sum;
		} else {
			if( (r1.end-r1.start) < (r2.end-r2.start) ) {
				max.start = r1.start;
				max.end = r1.end;
				max.sum = r1.sum;
			} else {
				max.start = r2.start;
				max.end = r2.end;
				max.sum = r2.sum;
			}
		}
		if(max.sum>res->sum) {
			res->start = max.start;
			res->end = max.end;
			res->sum = max.sum;
		} else if (max.sum == res->sum) {
			if( (max.end-max.start) < (res->end-res->start) ){
				res->start = max.start;
				res->end = max.end;
			}
		}
		//printf("res {%d:%d,%d}\n", res->start, res->end, res->sum);
	}
}

#pragma omp task final( n<seqlength || current>0 )
void maxSubseq(int current, const int seq[], const int n, Range *res) {
    if( n<seqlength || current>0) {
        maxSubseq_serial(current, seq, n, res);
    }
	//printf("current %d len %d\n", current, n);
	if(current!=n) {
		res->start=current;
		res->end=n;
		int i;
		if(seq[current]>0)
			for(i=current;i<n;i++)
				res->sum+=seq[i];
		Range r1, r2, max;
		r1.start=current+1; r2.start=current;
		r1.end=n; r2.end=n-1;
		r1.sum=r2.sum=0;
		maxSubseq(current+1, seq, n, &r1);
		if(seq[current]>0)
			maxSubseq(current, seq, n-1, &r2);
		#pragma omp taskwait
		//printf("res {%d:%d,%d} r1 {%d:%d,%d} r2 {%d:%d,%d}\n", res->start, res->end, res->sum, r1.start, r1.end, r1.sum, r2.start, r2.end, r2.sum);
		if(r1.sum>r2.sum) {
			max.start = r1.start;
			max.end = r1.end;
			max.sum = r1.sum;
		} else if (r2.sum>r1.sum) {
			max.start = r2.start;
			max.end = r2.end;
			max.sum = r2.sum;
		} else {
			if( (r1.end-r1.start) < (r2.end-r2.start) ) {
				max.start = r1.start;
				max.end = r1.end;
				max.sum = r1.sum;
			} else {
				max.start = r2.start;
				max.end = r2.end;
				max.sum = r2.sum;
			}
		}
		if(max.sum>res->sum) {
			res->start = max.start;
			res->end = max.end;
			res->sum = max.sum;
		} else if (max.sum == res->sum) {
			if( (max.end-max.start) < (res->end-res->start) ){
				res->start = max.start;
				res->end = max.end;
			}
		}
		//printf("res {%d:%d,%d}\n", res->start, res->end, res->sum);
	}
}

int main(int argc, char **argv) {
	const char *filename;
	int i;
	Range res;
	res.start = 0;
	res.sum=0;
	
	if(argc==3) {
		filename = argv[1];
		seqlength = atoi(argv[2]);
	}
	else {
		printf("./max_cont_seq_iter filename size\n");
		exit(0);
	}

	int seq[seqlength];
	FILE *f = fopen(filename, "r");
	for(i=0;i<seqlength;i++)
		fscanf(f, "%d", &seq[i]);
 
	double start = omp_get_wtime();
    maxSubseq(0, seq, seqlength, &res);
	#pragma omp taskwait
    double end = omp_get_wtime();
    printf("Max sum = %d\n", res.sum);
    printf("Start %d End %d\n", res.start, res.end);
    /*for (i = res.start; i < res.end; i++)
        printf("%d ", seq[i]);
    printf("\n");*/
 
	printf("time %f\n", end - start);
    return 0;
}
