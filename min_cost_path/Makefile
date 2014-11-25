all: mcp mcp_memo mcp_omp mcp_omp_memo mcp_omp_inst mcp_omp_memo_inst

mcp: mcp.c
	mcc mcp.c -o mcp

mcp_memo: mcp_memo.c
	mcc mcp_memo.c -o mcp_memo

mcp_omp: mcp_omp.c
	mcc mcp_omp.c -o mcp_omp --ompss

mcp_omp_memo: mcp_omp_memo.c
	mcc mcp_omp_memo.c -o mcp_omp_memo --ompss

mcp_omp_inst: mcp_omp.c
	mcc mcp_omp.c -o mcp_omp_inst --ompss --instrument

mcp_omp_memo_inst: mcp_omp_memo.c
	mcc mcp_omp_memo.c -o mcp_omp_memo_inst --ompss --instrument

clean:
	rm -f mcp mcp_memo mcp_omp mcp_omp_memo mcp_omp_inst mcp_omp_memo_inst *.o *~
