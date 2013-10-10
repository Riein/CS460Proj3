CC= -std=c99

SchedSim: main.o
	cc main.o -o SchedSim

main.o: main.c
	cc $(CC) -c main.c
