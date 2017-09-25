CC=gcc

CFLAGS=-I../include -c
LIBNAME= libred_black.a

archive: red_black.o
	ar -crv $(LIBNAME) red_black.o
	rm -rf red_black.o
avl.o: red_black.c
	$(CC) $(CFLAGS) red_black.c
