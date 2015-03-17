all: fib_memo fib_table fib_table_cpp fib_map

fib_memo: fib_memo.c
	icc -ipo -lrt fib_memo.c -o fib_memo

fib_table: fib_table.c
	icc -ipo -lrt fib_table.c -o fib_table

fib_table_cpp: fib_table_cpp.c Memo_wrapper.cpp
	icc -ipo -c -lrt fib_table_cpp.c 
	icpc -ipo -c Memo_wrapper.cpp -std=c++11
	icc -ipo -lrt -o fib_table_cpp fib_table_cpp.o Memo_wrapper.o -lstdc++
	rm *.o

fib_map: fib_map.c Memo_wrapper.cpp
	icc -ipo -c -lrt fib_map.c 
	icpc -ipo -c Memo_wrapper.cpp -std=c++11
	icc -ipo -lrt -o fib_map fib_map.o Memo_wrapper.o -lstdc++
	rm *.o

clean:
	rm -f fib_memo fib_table fib_table_cpp fib_map *.o *~
