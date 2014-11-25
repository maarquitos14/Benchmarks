#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <omp.h>

int N = 50;
long long unsigned int res_size;

void hanoi(int n, int src, int dst, int tmp, char * res) {
    if(n==0) {
        *res = '\0';
        return;
    }
    char *hold = malloc(2<<n-1*sizeof *hold);
    hanoi(n-1, src, tmp, dst, hold);
    char *result = (char*) calloc(2*(strlen(hold)+1), sizeof *result);
    strcpy(result, hold);
    free(hold);
    char addend[2] = "0";
    addend[0] = (char) ('0' + 3*src + dst);
    strcat(result, addend);
    char *other = malloc(2<<n-1*sizeof *hold);
    hanoi(n-1, tmp, dst, src, other);
    strcat(result, other);
    free(other);
    strcpy(res, result);
    free(result);
}

//void hanoi(int n, int src, int dst, int tmp, char * res) {
//    int  offset = (1 << (n-1)) - 1;
//    char *right = res + offset + 1;
//    if (n == 0) return;
//    hanoi(n-1, src, tmp, dst, res);
//    res[offset] = (char) ('0' + 3*src + dst);
//    hanoi(n-1, tmp, dst, src, right);
//}

int main(int argc, char *argv[]) {
    int n, src, dst, tmp;
    if(argc!=5) {
        printf("Usage: %s n src dst tmp\n", argv[0]);
        exit(0);
    }
    n = atoi(argv[1]);
    src = atoi(argv[2]);
    dst = atoi(argv[3]);
    tmp = atoi(argv[4]);
    res_size = (long long unsigned int)2<<n;
    char *res = (char *)calloc(res_size, sizeof(char));
    double start = omp_get_wtime();
    hanoi(n,src,dst,tmp,res);
    double end = omp_get_wtime();
    char output_file[16];
    sprintf(output_file, "output_%d.txt", n);
    FILE *out;
    out = fopen(output_file, "w");
    fprintf(out, "hanoi(%d,%d,%d,%d)=%s\n", n, src, dst, tmp, res);
    fclose(out);
    printf("time %f\n", end-start);
    free(res);
}
