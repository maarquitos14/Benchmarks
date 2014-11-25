all: bst bst_memo bst_omp bst_omp_memo bst_omp_inst bst_omp_memo_inst

bst: bst.c
	mcc bst.c -o bst

bst_memo: bst_memo.c
	mcc bst_memo.c -o bst_memo

bst_omp: bst_omp.c
	mcc bst_omp.c -o bst_omp --ompss 

bst_omp_memo: bst_omp_memo.c
	mcc bst_omp_memo.c -o bst_omp_memo --ompss 

bst_omp_inst: bst_omp.c
	mcc bst_omp.c -o bst_omp_inst --ompss 

bst_omp_memo_inst: bst_omp_memo.c
	mcc bst_omp_memo.c -o bst_omp_memo_inst --ompss 

clean:
	rm -f bst bst_memo bst_omp bst_omp_memo bst_omp_inst bst_omp_memo_inst *.o *~
