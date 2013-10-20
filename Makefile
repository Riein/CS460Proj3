CC = gcc
CFLAGS = -Wall -std=gnu99
PROG = SchedSim

all: $(PROG)

debug: CFLAGS += -DDEBUG=1 -g
debug: $(PROG)

$(PROG): main.o heap.o
	$(CC) $^ -o $@

main.o: main.c pcb.h
	$(CC) $(CFLAGS) -c main.c

heap.o: heap.h heap.c pcb.h
	$(CC) $(CFLAGS) -c heap.c

clean:
	rm -rf *.o $(PROG)