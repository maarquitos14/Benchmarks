all: knapsack knapsack_memo knapsack_omp knapsack_omp_memo

knapsack: knapsack.c
	mcc knapsack.c -o knapsack

knapsack_memo: knapsack_memo.c
	mcc knapsack_memo.c -o knapsack_memo

knapsack_omp: knapsack_omp.c
	mcc knapsack_omp.c -o knapsack_omp --ompss

knapsack_omp_memo: knapsack_omp_memo.c
	mcc knapsack_omp_memo.c -o knapsack_omp_memo --ompss

knapsack_omp_inst: knapsack_omp.c
	mcc knapsack_omp.c -o knapsack_omp_inst --ompss --instrument

knapsack_omp_memo_inst: knapsack_omp_memo.c
	mcc knapsack_omp_memo.c -o knapsack_omp_memo_inst --ompss --instrument

clean:
	rm -f knapsack knapsack_memo knapsack_omp knapsack_omp_memo knapsack_omp_inst knapsack_omp_memo_inst *.o *~
