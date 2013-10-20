#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


/* Min-heapify array A with n elements at index i. */
void minheap_heapify(PCB *A[], int i, int n){
	int right = 2 * (i+1);
	int left = right - 1;
	int min = i;
	PCB *tmp = 0;

	if (left < n && A[left]->priority < A[i]->priority) {
		min = left;
	}

	if (right < n && A[right]->priority < A[min]->priority) {
		min = right;
	}

	if (min != i) {
		tmp = A[i];
		A[i] = A[min];
		A[min] = tmp;

		minheap_heapify(A, min, n);
	}
}


/* 
 * Sort array A with n elements using min-heapify. Uses a for loop that calls
 * heapify for every parent node starting at the bottom.
 */
void minheap_build(PCB *A[], int n){
	for(int i = n; i > 0; i--){
		int parent = (i-1) / 2;
		minheap_heapify(A, parent, n);
	}
}


/* Pop the min element from the min heap. */
PCB *minheap_pop_min(PCB *A[], int *n) {
	/* Save root. */
	PCB *min = A[0];

	/* Move last node to root. */
	A[0] = A[*n - 1];
	A[*n - 1] = NULL;

	/* Resize heap. */
	A = realloc(A, sizeof(PCB *) * (*n - 1));
	*n -= 1;

	/* Re-heapify. */
	minheap_heapify(A, 0, *n);

	return min;
}


/* Insert a new item into the heap. */
void minheap_insert(PCB *A[], PCB *item, int *n) {
	/* TODO */
}

