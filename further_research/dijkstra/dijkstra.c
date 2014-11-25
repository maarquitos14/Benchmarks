#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <omp.h>

int n;
FILE *input_file;

void read_graph(int *g) {
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            fscanf(input_file, "%d", &g[i*n+j]);
        }
    }
}

void write_graph(int *g) {
    int i,j;
    for(i=0;i<n;++i) {
        for(j=0;j<n;++j) {
            printf("%d ", g[i*n+j]);
        }
        printf("\n");
    }
}

void print_path(int *prev, int end) {
    printf("The path is: ");
    int aux = end;
    while(aux!=-1) {
        printf("%d ", aux);
        aux = prev[aux];
    }
    printf("\n"); 
}

void Dijkstra(int *g, int start, int end, int *res, int *visited) {
    if(start == end) {
        *res = 0;
        printf("Distance from %d to %d is %d\n", start, end, *res);
        return;
    }
    int i;
    for(i=0;i<n;i++) {
        if(!visited[i] && g[end*n+i]) {
            int aux=INT_MAX;
            visited[i]=1;
            Dijkstra(g, start, i, &aux, visited);
            visited[i]=0;
            if( aux!=INT_MAX && (aux + g[end*n+i]) < *res) {
                *res = aux + g[end*n+i]; 
            }
        }
    }
    printf("Distance from %d to %d is %d\n", start, end, *res);
}

int main(int argc, char *argv[]) {
    char *filename;
    int i,j;
    if(argc != 3) {
        printf("usage: %s filename size\n", argv[0]);
        exit(0);
    }
    else {
        n = atoi(argv[2]);
        filename = argv[1];
        input_file = fopen(filename, "r");
    }
    int * visited = (int *) malloc(n*sizeof(int));
    for(i=0;i<n;i++) {
        visited[i]=0;
    }
    int *g = (int *) malloc(n*n*sizeof(int));
    read_graph(g);
    //write_graph(g);
    int start, end;
    fscanf(input_file, "%d %d", &start, &end);
    int res = INT_MAX;
    int prev[n];
    double start_time = omp_get_wtime();
    Dijkstra(g, start, end, &res, visited);
    double end_time = omp_get_wtime();
    printf("Distance from %d to %d is %d.\n", start, end, res);
    printf("Time %f\n", end_time-start_time);
    //print_path(prev, end);
    free(g);
    free(visited);
}
