CC=gcc
FLAGS= -I../include -g
EXECPATH= ../
OBJPATH= ../source/
LIBPATH= ../source/
LIBNAME= libred_black.a
LFLAGS= -lred_black -L$(LIBPATH)

default: main clean

main: main.o $(LIBPATH)$(LIBNAME)
	$(CC) -o$(EXECPATH)main main.o $(LFLAGS) -lpthread -g
main.o: main.c
	$(CC) $(FLAGS) -c main.c
clean:
	rm -rf main.o
