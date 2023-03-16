all: app

app: main.o intvector.o
	gcc -Wall -o app intvector.o main.o
main.o: main.c
	gcc -Wall -c -o main.o main.c
intvector.o: intvector.c
	gcc -Wall -c -o intvector.o intvector.c
