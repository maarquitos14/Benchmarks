#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)  {
	int i, j;
	char *output_file;
	if(argc!=3) {
		printf("./generate_input m n\n");
		exit(0);
	}
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
	sprintf(output_file, "input-%dx%d.txt", m, n);
	FILE *f=fopen(output_file, "w");
	srand(time(NULL));
	for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
			fprintf(f, "%d ", rand()%100);
        }
        fprintf(f, "\n");
    }
	return 0;
}
