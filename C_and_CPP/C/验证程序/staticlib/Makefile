edit: test.o static_lib.o
	cc -o edit test.o static_lib.o

test.o: test.c static_lib.h
	cc -c test.c

static_lib.o: static_lib.c
	cc -c static_lib.c

clean:
	rm edit test.o static_lib.o
