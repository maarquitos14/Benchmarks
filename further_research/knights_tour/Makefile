all: knights_tour knights_tour_omp knights_tour_omp_memo knights_tour_omp_inst knights_tour_omp_memo_inst

knights_tour: knights_tour.c
	mcc knights_tour.c -o knights_tour

knights_tour_omp: knights_tour_omp.c
	mcc knights_tour_omp.c -o knights_tour_omp --ompss

knights_tour_omp_memo: knights_tour_omp_memo.c
	mcc knights_tour_omp_memo.c -o knights_tour_omp_memo --ompss

knights_tour_omp_inst: knights_tour_omp.c
	mcc knights_tour_omp.c -o knights_tour_omp_inst --ompss --instrument

knights_tour_omp_memo_inst: knights_tour_omp_memo.c
	mcc knights_tour_omp_memo.c -o knights_tour_omp_memo_inst --ompss --instrument

clean:
	rm -f knights_tour knights_tour_omp knights_tour_omp_memo knights_tour_omp_inst knights_tour_omp_memo_inst *.o *~
