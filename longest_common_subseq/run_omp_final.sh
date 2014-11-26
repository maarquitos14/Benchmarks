#!/bin/bash

#BSUB -n 1
#BSUB -J lcs_omp 
#BSUB -oo lcs_omp.out
#BSUB -eo lcs_omp.err
#BSUB -W 00:10

for i in {1..5}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			./lcs_omp abcdefghijklmnopqr zyxwvutsrqponm 5
		elif test $i -eq 2
		then
			./lcs_omp abcdefghijklmnopqr zyxwvutsrqponml 5
		elif test $i -eq 3
		then
			./lcs_omp abcdefghijklmnopqr zyxwvutsrqponmlk 5
		elif test $i -eq 4
		then
			./lcs_omp abcdefghijklmnopqr zyxwvutsrqponmlkj 5
		else
			./lcs_omp abcdefghijklmnopqr zyxwvutsrqponmlkji 5
		fi
	done
done
