all: knapsack_iter knapsack_iter_omp

knapsack_iter: knapsack_iter.c
	mcc knapsack_iter.c -o knapsack_iter

knapsack_iter_omp: knapsack_iter_omp.c
	mcc knapsack_iter_omp.c -o knapsack_iter_omp --ompss

clean:
	rm -f knapsack_iter knapsack_iter_omp *.o *~
