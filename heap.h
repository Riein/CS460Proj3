#ifndef HEAP_H
#define HEAP_H

#include "pcb.h"

void minheap_heapify(PCB *A[], int i, int n);
void minheap_build(PCB *A[], int n);
PCB *minheap_pop_min(PCB *A[], int *n);
void minheap_insert(PCB *A[], PCB *item, int *n);

#endif
