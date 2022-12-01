CC=gcc
CFLAGS=-O2 -Wall

all: project

project: main.c List.o
	$(CC) $(CFLAGS) -o project $^

%o: %c %h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o project
