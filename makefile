all: main.o
	gcc -o program main.c

main.o: main.c
	gcc -c main.c

run:
	./program

clean:
	rm *.o

debug: main.c
	gcc -g main.c

gdb: a.out
	gdb a.out
