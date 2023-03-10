all: main.c Lista.c
	gcc -o main main.c Lista.c

main: main.c Lista.o
	gcc -o main main.c Lista.o

Lista.o: Lista.c
	gcc -c Lista.c
