all: fib fib_memo fib_omp fib_omp_memo fib_omp_inst fib_omp_memo_inst

fib: fib.c
	mcc fib.c -o fib

fib_memo: fib_memo.c
	mcc fib_memo.c -o fib_memo

fib_omp: fib_omp.c
	mcc fib_omp.c -o fib_omp --ompss

fib_omp_memo: fib_omp_memo.c
	mcc fib_omp_memo.c -o fib_omp_memo --ompss

fib_omp_inst: fib_omp.c
	mcc fib_omp.c -o fib_omp_inst --ompss --instrument

fib_omp_memo_inst: fib_omp_memo.c
	mcc fib_omp_memo.c -o fib_omp_memo_inst --ompss --instrument

clean:
	rm -f fib fib_memo fib_omp fib_omp_memo fib_omp_inst fib_omp_memo_inst *.o *~
