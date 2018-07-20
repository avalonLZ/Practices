a.out: main.o myprintf.o aprintf.o
	cc -o a.out main.o myprintf.o aprintf.o 

main.o: main.c mysprintf.h
	cc -c main.c 

myprintf.o: myprintf.c aprintf.h
	cc -c myprintf.c

aprintf.o: aprintf.c
	cc -c aprintf.c
clean: 
	rm a.out main.o myprintf.o aprintf.o
