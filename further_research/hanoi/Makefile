all: hanoi hanoi_omp hanoi_omp_memo hanoi_omp_inst hanoi_omp_memo_inst

hanoi: hanoi.c
	mcc hanoi.c -o hanoi

hanoi_omp: hanoi_omp.c
	mcc hanoi_omp.c -o hanoi_omp --ompss

hanoi_omp_memo: hanoi_omp_memo.c
	mcc hanoi_omp_memo.c -o hanoi_omp_memo --ompss

hanoi_omp_inst: hanoi_omp.c
	mcc hanoi_omp.c -o hanoi_omp_inst --ompss --instrument

hanoi_omp_memo_inst: hanoi_omp_memo.c
	mcc hanoi_omp_memo.c -o hanoi_omp_memo_inst --ompss --instrument

clean:
	rm -f hanoi hanoi_omp hanoi_omp_memo hanoi_omp_inst hanoi_omp_memo_inst *.o *~
