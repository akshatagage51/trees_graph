CC=gcc

CFLAGS=-I../include -c
LIBNAME= libgraph.a

archive: graph.o
	ar -crv $(LIBNAME) graph.o
	rm -rf graph.o
avl.o: graph.c
	$(CC) $(CFLAGS) graph.c
