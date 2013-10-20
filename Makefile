CC = gcc
CFLAGS = -Wall -std=c99
PROG = SchedSim

all: $(PROG)

debug: CFLAGS += -DDEBUG=1 -g
debug: $(PROG)

$(PROG): main.o
	$(CC) $^ -o $@

.c.o:
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o $(PROG)