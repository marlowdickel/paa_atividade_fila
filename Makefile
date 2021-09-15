SHELL=/bin/sh
CC=gcc
CFLAGS = -g3 -Wall -Wextra -fPIC -DREPLICATION_ENABLED -DJOURNALING_ENABLED -m64

default:  aplicacao 

fila.o:        fila.c fila_publico.h fila_privado.h
	$(CC) $(CFLAGS) -c fila.c -o fila.o

aplicacao:        aplicacao.c  aplicacao.h pilha.o fila.o
	$(CC) $(CFLAGS) aplicacao.c pilha.o fila.o -o aplicacao

clean:
	rm -f aplicacao *.o core a.out *.*~ Makefile~

all: aplicacao
