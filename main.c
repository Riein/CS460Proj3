/*
 * CS460 Project 3
 * Scheduler Sim
 * Corey Amoruso, Michael Swiger, Sasha Demiyanik
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 
 * Print program usage line to stdout. Takes string pn, which is the program 
 * name (typically argv[0]).
 */
void print_usage(const char *pn) {
	printf("Usage: %s <nprocs> <switch time> <RR|FCFS|SJF> [RR quantum]\n", pn);
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
		fprintf(stderr, "Error: nprocs must be greater than zero.\n");
		return 1;
	}

	if (cs < 0) {
		fprintf(stderr, "Error: switch time must be non-negative.\n");
		return 1;
	}

	/* Branch based on type. */
	if (strcmp(type, "FCFS") == 0) {
		/* TODO: Run schedule function. */
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

		/* TODO: Run schedule function. */
	} else if (strcmp(type, "SJF")) {
		/* TODO: Run schedule function. */
	} else {
		fprintf(stderr, "Error: Unknown type `%s'\n", type);
		return 1;
	}

	return 0;
}
