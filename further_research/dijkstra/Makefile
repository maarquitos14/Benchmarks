all: dijkstra dijkstra_omp dijkstra_c++

dijkstra: dijkstra.c
	smpcc dijkstra.c -o dijkstra --debug -k

dijkstra_omp: dijkstra_omp.c
	smpcc dijkstra_omp.c -o dijkstra_omp --ompss

dijkstra_c++: dijkstra.cpp
	smpcc dijkstra.cpp -o dijkstra_c++

clean:
	rm -f dijkstra dijkstra_omp dijkstra_c++ *.o *~
