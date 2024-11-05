#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char **argv){

	int stat=open(argv[1],O_RDONLY);
	if (stat<0){
		perror("could not open file");
		exit(5);
	}
	printf("normal execution\n");
	return 0;

}
