/*
 * CS460 Project 3
 * Scheduler Sim
 * Corey Amoruso, Michael Swiger, Sasha Demiyanik
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pcb.h"


/* 
 * Print program usage line to stdout. Takes string `pn', which is the program 
 * name (typically argv[0]).
 */
void print_usage(const char *pn) {
	printf("Usage: %s <nprocs> <switch time> <RR|FCFS|SJF> [RR quantum]\n", pn);
}


/* Compares arrival time in PCBs for qsort. */
int pcb_arrive_compare(const void *a, const void *b) {
	const PCB *p1 = *(PCB **) a;
	const PCB *p2 = *(PCB **) b;

	if (p1->time_arrived < p2->time_arrived) {
		return -1;
	} else if (p1->time_arrived > p2->time_arrived) {
		return 1;
	}

	return 0;
}


/* 
 * Build an array of PCBs of size nproc from stdin. Each line in stdin must
 * have an arrival time and a duration for a process delimited by a comma and
 * whitespace. Returns array of PCBs.
 */
PCB **build_procs(int nproc) {
	PCB **procs = (PCB **) malloc(sizeof(PCB *) * nproc);

	for (int i = 0; i < nproc; i++) {
		/* Read line from stdin. */
		char *line = NULL;
		size_t n;
		getline(&line, &n, stdin);

		/* Parse the line and store it in a new PCB. */
		PCB *p = (PCB *) malloc(sizeof(PCB));
		sscanf(line, "%d, %d\n", &(p->time_arrived), &(p->time_left));

		/* Save the new PCB in the procs array. */
		procs[i] = p;

		/* Free the memory used in getline. */
		free(line);
	}
	
	/* Sort the procs by arrival time. */
	qsort(procs, nproc, sizeof(PCB *), pcb_arrive_compare);

	return procs;
}


/* Run the FCFS scheduler on the given procs. */
void run_fcfs_scheduler(PCB **procs, int nprocs, int cs) {
    /* TODO: Implement. */
}


/* Run the RR scheduler on the given procs. */
void run_rr_scheduler(PCB **procs, int nprocs, int cs, int q) {
    /* TODO: Implement. */
}


/* Run the SJF scheduler on the given procs. */
void run_sjf_scheduler(PCB **procs, int nprocs, int cs) {
    /* TODO: Implement. */
}


/* Program entry point. */
int main(int argc, char *argv[]){
	if (argc < 4) {
		print_usage(argv[0]);
		return 1;
	}

	/* Get common command line arguments. */
	int nproc = atoi(argv[1]);
	int cs = atoi(argv[2]);
	const char *type = argv[3];

	/* Verify common arguments. */
	if (nproc < 1) {
		fprintf(stderr, "Error: nproc must be greater than zero.\n");
		return 1;
	}

	if (cs < 0) {
		fprintf(stderr, "Error: switch time must be non-negative.\n");
		return 1;
	}

	/* Allocate processes array and read input. */
	PCB **procs = build_procs(nproc);
	
	for (int i = 0; i < nproc; i++) {
		printf("Arrival time: %d\n", procs[i]->time_arrived);
	}

	/* Branch based on type. */
	if (strcmp(type, "FCFS") == 0) {
		run_fcfs_scheduler(procs, nproc, cs);
	} else if (strcmp(type, "RR") == 0) {
		/* Need time quantum for RR. */
		if (argc < 5) {
			fprintf(stderr, "Error: must specify quantum for RR.\n");
			return 1;
		}

		/* Verify time quantum is positive. */
		int q = atoi(argv[4]);

		if (q < 0) {
			fprintf(stderr, "Error: time quantum must be positive.\n");
		}

		run_rr_scheduler(procs, nproc, cs, q);
	} else if (strcmp(type, "SJF")) {
		run_sjf_scheduler(procs, nproc, cs);
	} else {
		fprintf(stderr, "Error: Unknown type `%s'\n", type);
		return 1;
	}

	/* Free all of the PCBs and the procs array. */
	for (int i = 0; i < nproc; i++) {
		free(procs[i]);
	}

	free(procs);

	return 0;
}
