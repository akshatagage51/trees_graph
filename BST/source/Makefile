CC=gcc

CFLAGS=-I../include -c
LIBNAME= libbst.a

archive: bst.o
	ar -crv $(LIBNAME) bst.o
	rm -rf bst.o
bst.o: bst.c
	$(CC) $(CFLAGS) bst.c
