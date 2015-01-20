all: levenshtein_distance levenshtein_distance_memo levenshtein_distance_omp levenshtein_distance_omp_memo

levenshtein_distance: levenshtein_distance.c
	mcc levenshtein_distance.c -o levenshtein_distance

levenshtein_distance_memo: levenshtein_distance_memo.c
	mcc levenshtein_distance_memo.c -o levenshtein_distance_memo

levenshtein_distance_omp: levenshtein_distance_omp.c
	mcc levenshtein_distance_omp.c -o levenshtein_distance_omp --ompss

levenshtein_distance_omp_memo: levenshtein_distance_omp_memo.c
	mcc levenshtein_distance_omp_memo.c -o levenshtein_distance_omp_memo --ompss

levenshtein_distance_omp_inst: levenshtein_distance_omp.c
	mcc levenshtein_distance_omp.c -o levenshtein_distance_omp_inst --ompss --instrument

levenshtein_distance_omp_memo_inst: levenshtein_distance_omp_memo.c
	mcc levenshtein_distance_omp_memo.c -o levenshtein_distance_omp_memo_inst --ompss --instrument

clean:
	rm -f levenshtein_distance levenshtein_distance_memo levenshtein_distance_omp levenshtein_distance_omp_memo levenshtein_distance_omp_inst levenshtein_distance_omp_memo_inst *.o *~
