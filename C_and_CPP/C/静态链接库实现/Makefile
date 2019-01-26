
main: main.o libmy_printf.a
	cc -o main main.o -L . -lmy_printf

main.o: main.c my_printf.h
	cc -c main.c

libmy_printf.a: my_printf.o
	ar -rcs libmy_printf.a my_printf.o

my_printf.o: my_printf.c my_printf.h
	cc -c my_printf.c

clean:
	rm -rf my_printf.o libmy_printf.a main.o main

