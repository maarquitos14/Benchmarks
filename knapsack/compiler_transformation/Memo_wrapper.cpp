#if 0
#include "Memoization.cpp"
extern "C" {
    Memoization * new_memo() {
        Memoization * memo = new Memoization();
        return memo;
    }
    
    void delete_memo( Memoization * memo ) {
        delete memo;
    }

    int get_element( Memoization * memo, int index ) {
        return memo->get_element( index );
    }
    void set_element( Memoization * memo, int index, int res ) {
        memo->set_element( index, res );
    }
}
#endif

#if 0
#include<unordered_map>
#include<stdio.h>
std::unordered_map<int, int> memo;
extern "C" {
    void init( int size ) {
    }

    int get_element( int index ) {
        if( memo.find(index)!=memo.end()) return memo[index];
        else return -1;
        //return index;
    }

    void set_element( int index, int res ) {
        memo[index] = res;
    }
}
#endif

#if 1
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int *__restrict__ memo;
extern "C" {
    void init( int size ) {
        //printf("table");
        memo = (int *) _mm_malloc(size*sizeof(int), 64);
        memset(memo, -1, size*sizeof(int));
    }

    void destroy() {
        delete memo;
    }

    int get_element( int index ) {
        __assume_aligned(memo, 64);
        return memo[index];
    }

    void set_element( int index, int res ) {
        __assume_aligned(memo, 64);
        memo[index] = res;
    }
}
#endif
