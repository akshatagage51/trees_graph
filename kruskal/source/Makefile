CC=gcc

CFLAGS=-I../include -c
LIBNAME= libkruskal.a

archive: kruskal.o
	ar -crv $(LIBNAME) kruskal.o
	rm -rf kruskal.o
bst.o: kruskal.c
	$(CC) $(CFLAGS) kruskal.c
