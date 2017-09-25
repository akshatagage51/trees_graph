CC=gcc

CFLAGS=-I../include -c
LIBNAME= libprim.a

archive: prim.o
	ar -crv $(LIBNAME) prim.o
	rm -rf prim.o
bst.o: prim.c
	$(CC) $(CFLAGS) prim.c
