#ifndef PCB_H
#define PCB_H

typedef struct {
	int priority;
	int pid;
	int time_left;
	int time_arrived;
	int time_waiting;
	int turnaround;
} PCB;

#endif
