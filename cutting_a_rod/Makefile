all: car car_memo car_omp car_omp_memo car_omp_inst car_omp_memo_inst

car: car.c
	mcc car.c -o car

car_memo: car_memo.c
	mcc car_memo.c -o car_memo

car_omp: car_omp.c
	mcc car_omp.c -o car_omp --ompss

car_omp_memo: car_omp_memo.c
	mcc car_omp_memo.c -o car_omp_memo --ompss

car_omp_inst: car_omp.c
	mcc car_omp.c -o car_omp_inst --ompss --instrument

car_omp_memo_inst: car_omp_memo.c
	mcc car_omp_memo.c -o car_omp_memo_inst --ompss --instrument

clean:
	rm -f car car_memo car_omp car_omp_memo car_omp_inst car_omp_memo_inst *.o *~
