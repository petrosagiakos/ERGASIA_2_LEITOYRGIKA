#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "buff_clean.h"

int buff_copy(int buffer, char *name1, char *name2){
	int fr_file=open(name1,O_RDONLY);
	if(fr_file<0){
		perror("could not open file");
		return 1;	
	}
	int tw_file=open(name2, O_WRONLY|O_CREAT,0600);
	if(tw_file<0){
		perror("could not open file");
		return 1;
	}
	char buff[buffer];
	int wr_stat;
	int chars_read=read(fr_file,buff,buffer);
	while(chars_read>0){
		wr_stat=write(tw_file,buff,chars_read);
		if(wr_stat<0){
			perror("error while writing");
			return 3;
		}
		chars_read=read(fr_file,buff,buffer);
	}
	if (chars_read<0){
		perror("error occured while reading");
		return 2;
	}
	close(fr_file);
	close(tw_file);
	return 0;
		
}
	
int main(int argc, char **argv){
	if (argc>3){
		int number=buffer_clean(argv[1]);
		int stat=buff_copy(number,argv[2],argv[3]);
		if(stat==0){
			printf("normal execution\n");
			return stat;
		}else{
			return stat;
		}
	}
	return 0;
}
