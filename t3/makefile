mycp: mycp.o buff_clean.o
	gcc -o mycp mycp.o buff_clean.o
buff_clean.o: buff_clean.c buff_clean.h
	gcc -c buff_clean.c
mycp.o: mycp.c buff_clean.h
	gcc -c mycp.c
