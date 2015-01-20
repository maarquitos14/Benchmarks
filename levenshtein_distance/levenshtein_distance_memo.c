#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int ori_len_t;
int *memo;

int min(int a, int b) {
    return a < b ? a : b;
}

void levenshteinDistance( char * s, int len_s, char * t, int len_t, int * res ) {
    int tmp;
    if( !len_s && !len_t ) {
        *res = 0;
        return;
    }

    if( !len_s ) {
        *res = len_t;
        return;
    }

    if( !len_t ) {
        *res = len_s;
        return;
    }

    if( s[len_s-1] == t[len_t-1] ) {
        tmp = 0;
    }
    else {
        tmp = 1;
    }

    int aux1, aux2, aux3;
    if(memo[(len_s-1)*ori_len_t+len_t] == -1) {
        levenshteinDistance( s, len_s-1, t, len_t, &aux1 );
        memo[(len_s-1)*ori_len_t+len_t] = aux1;
    }
    if(memo[len_s*ori_len_t+(len_t-1)] == -1) {
        levenshteinDistance( s, len_s, t, len_t-1, &aux2 );
        memo[len_s*ori_len_t+(len_t-1)] = aux2;
    }
    if(memo[(len_s-1)*ori_len_t+(len_t-1)] == -1) {
        levenshteinDistance( s, len_s-1, t, len_t-1, &aux3 );
        memo[(len_s-1)*ori_len_t+(len_t-1)] = aux3;
    }

    *res = min( min( memo[(len_s-1)*ori_len_t+len_t]+1, memo[len_s*ori_len_t+(len_t-1)]+1 ), memo[(len_s-1)*ori_len_t+(len_t-1)]+tmp );
}

int main( int argc, char * argv[] ) {
    if( argc != 2)  {
        printf( "usage: %s filename\n", argv[0] );
        exit(0);
    }

    const char *filename = argv[1];
	FILE *f = fopen(filename, "r");
    char s[1000];
    char t[1000];
    fscanf(f, "%s", &s); 
    fscanf(f, "%s", &t); 
    ori_len_t = strlen(t)+1;
    memo = calloc((strlen(s)+1)*(ori_len_t), sizeof(int));
    memset(memo, -1,(strlen(s)+1)*(strlen(t)+1)*sizeof(int));
    int res = 0;
    double start = omp_get_wtime();
    levenshteinDistance( s, strlen(s), t, strlen(t), &res );
    double end = omp_get_wtime();
    printf("Levenshtein distance %d, time %f\n", res, end-start);
    fclose(f);
}
