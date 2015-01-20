all: edp edp_memo edp_omp edp_omp_memo

edp: edp.c
	mcc edp.c -o edp

edp_memo: edp_memo.c
	mcc edp_memo.c -o edp_memo

edp_omp: edp_omp.c
	mcc edp_omp.c -o edp_omp --ompss

edp_omp_memo: edp_omp_memo.c
	mcc edp_omp_memo.c -o edp_omp_memo --ompss

edp_omp_inst: edp_omp.c
	mcc edp_omp.c -o edp_omp_inst --ompss --instrument

edp_omp_memo_inst: edp_omp_memo.c
	mcc edp_omp_memo.c -o edp_omp_memo_inst --ompss --instrument

clean:
	rm -f edp edp_memo edp_omp edp_omp_memo edp_omp_inst edp_omp_memo_inst *.o *~
