all: max_cont_seq_rec max_cont_seq_rec_omp max_cont_seq_rec_omp2

max_cont_seq_rec: max_cont_seq_rec.c
	mcc max_cont_seq_rec.c -o max_cont_seq_rec

max_cont_seq_rec_omp: max_cont_seq_rec_omp.c
	mcc max_cont_seq_rec_omp.c -o max_cont_seq_rec_omp --ompss

max_cont_seq_rec_omp2: max_cont_seq_rec_omp2.c
	mcc max_cont_seq_rec_omp2.c -o max_cont_seq_rec_omp2 --ompss

clean:
	rm -f max_cont_seq_rec max_cont_seq_rec_omp max_cont_seq_rec_omp2 *.o *~
