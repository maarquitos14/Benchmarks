all: nqueens_global nqueens_global_omp nqueens_global_omp_memo nqueens_global_omp_inst nqueens_global_omp_memo_inst 

nqueens_local: nqueens_local.c
	mcc nqueens_local.c -o nqueens_local	
	
nqueens_global: nqueens_global.c
	mcc nqueens_global.c -o nqueens_global

nqueens_global_omp: nqueens_global_omp.c
	mcc nqueens_global_omp.c -o nqueens_global_omp --ompss
	
nqueens_global_omp_memo: nqueens_global_omp_memo.c
	mcc nqueens_global_omp_memo.c -o nqueens_global_omp_memo --ompss

nqueens_global_omp_inst: nqueens_global_omp.c
	mcc nqueens_global_omp.c -o nqueens_global_omp_inst --ompss --instrument
	
nqueens_global_omp_memo_inst: nqueens_global_omp_memo.c
	mcc nqueens_global_omp_memo.c -o nqueens_global_omp_memo_inst --ompss --instrument

clean:
	rm -f nqueens_global nqueens_global_omp nqueens_global_omp_memo nqueens_global_omp_inst nqueens_global_omp_memo_inst *.o *~
