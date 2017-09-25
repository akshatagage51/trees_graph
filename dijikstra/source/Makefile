CC=gcc

CFLAGS=-I../include -c
LIBNAME= libdigi.a

archive: digi.o
	ar -crv $(LIBNAME) digi.o
	rm -rf digi.o
bst.o: digi.c
	$(CC) $(CFLAGS) digi.c
