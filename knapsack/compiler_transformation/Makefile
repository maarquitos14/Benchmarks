all: knapsack_memo knapsack_table knapsack_table_cpp knapsack_map

knapsack_memo: knapsack_memo.c
	icc -ipo -lrt knapsack_memo.c -o knapsack_memo

knapsack_table: knapsack_table.c
	icc -ipo -lrt knapsack_table.c -o knapsack_table

knapsack_table_cpp: knapsack_table_cpp.c Memo_wrapper.cpp
	icc -ipo -c -lrt knapsack_table_cpp.c 
	icpc -ipo -c Memo_wrapper.cpp -std=c++11
	icc -ipo -lrt -o knapsack_table_cpp knapsack_table_cpp.o Memo_wrapper.o -lstdc++
	rm *.o

knapsack_map: knapsack_map.c Memo_wrapper.cpp
	icc -ipo -c -lrt knapsack_map.c 
	icpc -ipo -c Memo_wrapper.cpp -std=c++11
	icc -ipo -lrt -o knapsack_map knapsack_map.o Memo_wrapper.o -lstdc++
	rm *.o

clean:
	rm -f knapsack_memo knapsack_table knapsack_table_cpp knapsack_map *.o *~
