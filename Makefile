CC = gcc
CFLAGS = -g -Wall -std=c99
PROG = SchedSim

all: $(PROG)

$(PROG): main.o
	$(CC) $^ -o $@

.c.o:
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o $(PROG)