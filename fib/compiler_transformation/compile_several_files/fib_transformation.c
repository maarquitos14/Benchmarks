extern int *table;
//#pragma memo transform index(n) init(-1)
//int fib(int n)
//{
//	if(n<2) return n;
//    else return fib(n-1)+fib(n-2);
//}
//fib has to be redefined to receive the table pointer.
//int fib(int n, int* memo) {
//    if(n<2) return n;
//    else {
//        if(memo[n-1]==-1) memo[n-1]=fib(n-1, memo);
//        if(memo[n-2]==-1) memo[n-2]=fib(n-2, memo);
//        return memo[n-1]+memo[n-2];
//    }
//}
int fib(int n) {
    if(n<2) return n;
    else {
        if(table[n-1]==-1) table[n-1]=fib(n-1);
        if(table[n-2]==-1) table[n-2]=fib(n-2);
        return table[n-1]+table[n-2];
    }
}
