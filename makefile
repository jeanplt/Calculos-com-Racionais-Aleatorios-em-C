# Makefile 
     
CFLAGS = -Wall # flags de compilacao
CC = gcc

all: resolveRacionais.o racionais.o
	$(CC) -o resolveRacionais resolveRacionais.o racionais.o

racionais.o: racionais.c
	$(CC) -c $(CFLAGS) racionais.c

resolveRacionais.o: resolveRacionais.c
	$(CC) -c $(CFLAGS) resolveRacionais.c

clean:
	rm -f *.o resolveRacionais
