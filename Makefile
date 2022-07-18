all: compilation execution

compilation: Sources/*.c main.c Headers/
	gcc -Wall main.c Sources/*.c -I Headers/ -o main.o -lm

execution: main.o
	./main.o


