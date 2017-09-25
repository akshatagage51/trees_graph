CC=gcc

CFLAGS=-I../include -c
LIBNAME= libavl.a

archive: avl.o
	ar -crv $(LIBNAME) avl.o
	rm -rf avl.o
avl.o: avl.c
	$(CC) $(CFLAGS) avl.c
