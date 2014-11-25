all: lis lis_memo lis_omp lis_omp_memo lis_omp_inst lis_omp_memo_inst

lis: lis.c
	mcc lis.c -o lis

lis_memo: lis_memo.c
	mcc lis_memo.c -o lis_memo

lis_omp: lis_omp.c
	mcc lis_omp.c -o lis_omp --ompss

lis_omp_memo: lis_omp_memo.c
	mcc lis_omp_memo.c -o lis_omp_memo --ompss

lis_omp_inst: lis_omp.c
	mcc lis_omp.c -o lis_omp_inst --ompss --instrument

lis_omp_memo_inst: lis_omp_memo.c
	mcc lis_omp_memo.c -o lis_omp_memo_inst --ompss --instrument

clean:
	rm -f lis lis_memo lis_omp lis_omp_memo lis_omp_inst lis_omp_memo_inst *.o *~
