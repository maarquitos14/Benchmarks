all: mcm mcm_memo mcm_omp mcm_omp_memo

mcm: mcm.c
	mcc mcm.c -o mcm

mcm_memo: mcm_memo.c
	mcc mcm_memo.c -o mcm_memo

mcm_omp: mcm_omp.c
	mcc mcm_omp.c -o mcm_omp --ompss

mcm_omp_memo: mcm_omp_memo.c
	mcc mcm_omp_memo.c -o mcm_omp_memo --ompss

mcm_omp_inst: mcm_omp.c
	mcc mcm_omp.c -o mcm_omp_inst --ompss --instrument

mcm_omp_memo_inst: mcm_omp_memo.c
	mcc mcm_omp_memo.c -o mcm_omp_memo_inst --ompss --instrument

clean:
	rm -f mcm mcm_memo mcm_omp mcm_omp_memo mcm_omp_inst mcm_omp_memo_inst *.o *~
