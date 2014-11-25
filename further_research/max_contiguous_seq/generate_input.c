#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)  {
	int size, i;
	FILE *f;
	char *output_file;
	
	if(argc==2) {
		size = atoi(argv[1]);
	}
	else {
		printf("./generate_input size\n");
		exit(0);
	}
	
	sprintf(output_file, "random-%d.txt", size);
	f=fopen(output_file, "w");
	srand(time(NULL));
	for(i=0;i<size;i++)
		if(i%2==0)
			fprintf(f, "%d ", rand()%10);
		else
			fprintf(f, "%d ", -(rand()%10));
	fprintf(f, "\n");
	
	return 0;
}
