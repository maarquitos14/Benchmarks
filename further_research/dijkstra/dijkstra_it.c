#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int n;
char * visited;
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

int minDistance(int dist[], int visited[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v]; 
            min_index = v;
        }

    return min_index;
}

void Dijkstra (int * g, int start, int end, int *res, int *prev) {
    int dist[n], visited[n];
    dist[start] = 0;
    visited[start] = 0;
    prev[start] = -1;
    int i;
    
    for(i=0;i<n;i++) {
        if(i!=start) {
            dist[i]=INT_MAX;
            prev[i]=-1;
            visited[i]=0;
        }
    }

    for(i=0;i<n;i++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        if(u==end) {
            *res = dist[u];
            return;
        }
        int v;
        for(v=0;v<n;v++) {
            if(!visited[v] && g[u*n+v] && dist[u]!=INT_MAX && dist[u]+g[u*n+v] < dist[v]) {
                dist[v] = dist[u]+g[u*n+v];
                prev[v] = u;
            }
        }
    }

    *res = -1;
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
    visited = (char *) malloc(n*sizeof(char));
    for(i=0;i<n;i++) {
        visited[i]=0;
    }
    int g[n*n];
    read_graph(g);
    //write_graph(g);
    int start, end;
    fscanf(input_file, "%d %d", &start, &end);
    int res = INT_MAX;
    int prev[n];
    Dijkstra(g, start, end, &res, prev);
    printf("Distance from %d to %d is %d.\n", start, end, res);
    //print_path(prev, end);
    free(g);
    free(visited);
    free(prev);
}
