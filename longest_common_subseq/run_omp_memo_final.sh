#!/bin/bash

#BSUB -n 1
#BSUB -J lcs_omp_memo 
#BSUB -oo lcs_omp_memo.out
#BSUB -eo lcs_omp_memo.err
#BSUB -W 00:10

for i in {1..5}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			./lcs_omp_memo abcdefghijklmnopqr zyxwvutsrqponm 6
		elif test $i -eq 2
		then
			./lcs_omp_memo abcdefghijklmnopqr zyxwvutsrqponml 6
		elif test $i -eq 3
		then
			./lcs_omp_memo abcdefghijklmnopqr zyxwvutsrqponmlk 6
		elif test $i -eq 4
		then
			./lcs_omp_memo abcdefghijklmnopqr zyxwvutsrqponmlkj 6
		else
			./lcs_omp_memo abcdefghijklmnopqr zyxwvutsrqponmlkji 6
		fi
	done
done

