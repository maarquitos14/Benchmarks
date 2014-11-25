all: max_cont_seq_iter max_cont_seq_iter_omp

max_cont_seq_iter: max_cont_seq_iter.c
	mcc max_cont_seq_iter.c -o max_cont_seq_iter

max_cont_seq_iter_omp: max_cont_seq_iter_omp.c
	mcc max_cont_seq_iter_omp.c -o max_cont_seq_iter_omp --ompss

clean:
	rm -f max_cont_seq_iter max_cont_seq_iter_omp *.o *~
