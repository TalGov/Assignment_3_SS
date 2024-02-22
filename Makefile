CC = gcc
CFLAGS = -Wall

all: StrList

StrList: Main.o StrList.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c Main.c -o Main.o

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c -o StrList.o

clean:
	rm -f *.o StrList