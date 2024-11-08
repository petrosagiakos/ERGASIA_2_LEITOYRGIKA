#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffer_clean(char *buff){
	char new_b[strlen(buff)*sizeof(char)];
	int cnt=0;
	char c=buff[cnt+2];
	while(c!='\0'){
		new_b[cnt]=c;
		cnt++;
		c=buff[cnt+2];
	}
	int num=atoi(new_b);

	return num;
}
