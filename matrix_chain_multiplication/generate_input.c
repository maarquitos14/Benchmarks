#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)  {
	int i;
	char *output_file;
	if(argc!=2) {
		printf("./generate_input size\n");
		exit(0);
	}
    int size = atoi(argv[1]);
	sprintf(output_file, "input-%d.txt", size);
	FILE *f=fopen(output_file, "w");
	srand(time(NULL));
	for(i=0;i<size;i++)
			fprintf(f, "%d ", rand()%100);
	fprintf(f, "\n");
	return 0;
}
