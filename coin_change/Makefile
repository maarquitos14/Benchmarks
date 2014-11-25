all: coin_change coin_change_memo coin_change_omp coin_change_omp_memo coin_change_omp_inst coin_change_omp_memo_inst

coin_change: coin_change.c
	mcc coin_change.c -o coin_change

coin_change_memo: coin_change_memo.c
	mcc coin_change_memo.c -o coin_change_memo

coin_change_omp: coin_change_omp.c
	mcc coin_change_omp.c -o coin_change_omp --ompss

coin_change_omp_memo: coin_change_omp_memo.c
	mcc coin_change_omp_memo.c -o coin_change_omp_memo --ompss

coin_change_omp_inst: coin_change_omp.c
	mcc coin_change_omp.c -o coin_change_omp_inst --ompss --instrument

coin_change_omp_memo_inst: coin_change_omp_memo.c
	mcc coin_change_omp_memo.c -o coin_change_omp_memo_inst --ompss --instrument

clean:
	rm -f coin_change coin_change_memo coin_change_omp coin_change_omp_memo coin_change_omp_inst coin_change_omp_memo_inst *.o *~
