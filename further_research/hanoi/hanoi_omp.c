#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <omp.h>

int N = 50;
int ori_n;
long long unsigned int res_size;

void hanoi_serial(int n, int src, int dst, int tmp, char * res) {
    if(n==0) {
        *res = 0;
        return;
    }
    char *hold = malloc(2<<(n-1)*sizeof *hold);
    hanoi_serial(n-1, src, tmp, dst, hold);
    char *result = (char*) calloc(2*(strlen(hold)+1), sizeof *result);
    strcpy(result, hold);
    free(hold);
    char addend[2] = "0";
    addend[0] = (char) ('0' + 3*src + dst);
    strcat(result, addend);
    char *other = malloc(2<<(n-1)*sizeof *hold);
    hanoi_serial(n-1, tmp, dst, src, other);
    strcat(result, other);
    free(other);
    strcpy(res, result);
    free(result);
}

#pragma omp task
void hanoi(int n, int src, int dst, int tmp, char * res) {
    //if(n < ori_n-3) {
    //    hanoi_serial(n, src, dst, tmp, res);
    //    return;
    //}
    if(n==0) {
        *res = 0;
        return;
    }
    char *hold = malloc(2<<(n-1)*sizeof *hold);
    hanoi(n-1, src, tmp, dst, hold);
    char addend[2] = "0";
    addend[0] = (char) ('0' + 3*src + dst);
    char *other = malloc(2<<(n-1)*sizeof *hold);
    hanoi(n-1, tmp, dst, src, other);
    #pragma omp taskwait
    char *result = (char*) calloc(2*(strlen(hold)+1), sizeof *result);
    strcpy(result, hold);
    strcat(result, addend);
    strcat(result, other);
    strcpy(res, result);
    free(hold);
    free(other);
    free(result);
}

int main(int argc, char *argv[]) {
    int n, src, dst, tmp;
    if(argc!=5) {
        printf("Usage: %s n src dst tmp\n", argv[0]);
        exit(0);
    }
    n = atoi(argv[1]);
    ori_n = n;
    src = atoi(argv[2]);
    dst = atoi(argv[3]);
    tmp = atoi(argv[4]);
    res_size = (long long unsigned int) 2<<n;
    char *res = (char *)calloc(res_size, sizeof(char));
    double start = omp_get_wtime();
    hanoi(n,src,dst,tmp,res);
    #pragma omp taskwait
    double end = omp_get_wtime();
    char output_file[20];
    sprintf(output_file, "output_omp_%d.txt", n);
    FILE *out;
    out = fopen(output_file, "w+");
    fprintf(out, "hanoi(%d,%d,%d,%d)=%s\n", n, src, dst, tmp, res);
    fclose(out);
    printf("time %f\n", end-start);
    free(res);
}
