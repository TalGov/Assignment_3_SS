CC = gcc
CFLAGS = -Wall

all: StrList

StrList: main.o StrList.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c StrList.h
	$(CC) $(CFLAGS) -c main.c -o main.o

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c -o StrList.o

clean:
	rm -f *.o StrList.exe