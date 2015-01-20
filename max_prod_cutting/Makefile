all: mpc mpc_memo mpc_omp mpc_omp_memo

mpc: mpc.c
	mcc mpc.c -o mpc

mpc_memo: mpc_memo.c
	mcc mpc_memo.c -o mpc_memo

mpc_omp: mpc_omp.c
	mcc mpc_omp.c -o mpc_omp --ompss

mpc_omp_memo: mpc_omp_memo.c
	mcc mpc_omp_memo.c -o mpc_omp_memo --ompss

mpc_omp_inst: mpc_omp.c
	mcc mpc_omp.c -o mpc_omp_inst --ompss --instrument

mpc_omp_memo_inst: mpc_omp_memo.c
	mcc mpc_omp_memo.c -o mpc_omp_memo_inst --ompss --instrument

clean:
	rm -f mpc mpc_memo mpc_omp mpc_omp_memo mpc_omp_inst mpc_omp_memo_inst *.o *~
