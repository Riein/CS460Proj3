/*
 * Project 3
 * Scheduler
 * CS460
 * Corey Amoruso
 * Michael Swiger
 * Sasha Demiyanik*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEBUG 1

int nproc = 0;
int cs = 0;
char* type = NULL;
int q = 0;

void checkArguments(int argc,char *argv[]){

	//checks to see the minimum number of arguemnts was supplied
	if(argc < 3){
		printf("Not enough arguments supplied. Please use format: ./SchedSim (int)nproc (int)cs (str)type [(int) q)]\n");
		exit(1);
	}

	//checks the nproc variable for correctness
	nproc = atoi(argv[1]);

	if(DEBUG){ printf("nproc = %d\n", nproc);}

	while(nproc < 0 ){
		printf("Error: You specified less than zero process are to be simulated. Please specify nproc > 0.\nnproc = ");
		fscanf(stdin, "%d", &nproc);
		if(DEBUG){ printf("nproc = %d\n", nproc);}
	}



	//checks the cs variable for correctness
	cs = atoi(argv[2]);
	
	if(DEBUG){ printf("cs = %d\n", cs);}

	while(cs < 0 ){
		printf("Error: You specified a context switch time of less than zero.\ncs = ");
		fscanf(stdin, "%d", &cs);
		if(DEBUG){ printf("cs = %d\n", cs);}
	}


	//checks the type for correctness
	type = argv[3];

	if(DEBUG){ printf("Specified type: %s\n", type);}

	while(strcmp(type,"FCFS") && strcmp(type,"RR") && strcmp(type,"SJF")){
		printf("Error: The type you specified is not FCFS, RR, or SJF. Please respecify the type.\nType = ");
		fscanf(stdin, "%s", type);
		if(DEBUG){ printf("type = %s\n", type);}
	}


	if(!strcmp(type,"RR")){
		if(argc < 4){
			printf("Please specify a time quantum for RR.\nq = ");
			fscanf(stdin,"%d",&q);
			while(q < 0){
				
			}
		}	

}

int main(int argc, char *argv[]){

	checkArguments(argc, argv);

	return 0;
}
