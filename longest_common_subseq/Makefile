all: lcs lcs_memo lcs_omp lcs_omp_memo lcs_omp_inst lcs_omp_memo_inst

lcs: lcs.c
	mcc lcs.c -o lcs

lcs_memo: lcs_memo.c
	mcc lcs_memo.c -o lcs_memo

lcs_omp: lcs_omp.c
	mcc lcs_omp.c -o lcs_omp --ompss

lcs_omp_memo: lcs_omp_memo.c
	mcc lcs_omp_memo.c -o lcs_omp_memo --ompss

lcs_omp_inst: lcs_omp.c
	mcc lcs_omp.c -o lcs_omp_inst --ompss --instrument

lcs_omp_memo_inst: lcs_omp_memo.c
	mcc lcs_omp_memo.c -o lcs_omp_memo_inst --ompss --instrument

clean:
	rm -f lcs lcs_memo lcs_omp lcs_omp_memo lcs_omp_inst lcs_omp_memo_inst *.o *~
