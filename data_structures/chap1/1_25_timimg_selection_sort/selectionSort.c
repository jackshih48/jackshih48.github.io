#include "selectionSort.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void sort (int list[], int n);

/* Selection Sort */
void sort(int list[], int n)
{
	int i, j, min, temp;
	 
	for(i = 0; i < n-1; i++) {
		min = i;
		for (j = i+1; j < n; j++) {
			if (list[j] < list[min]) {
				min = j;
			}
		}
		SWAP(list[i], list[min], temp);
	}
}

#if 0
/* Test main */
int main(void)
{
	int i, n;
	int list[MAX_SIZE];
	
	/* Input */
	printf("Enter the number of numbers to generate randomly: ");
	scanf("%d", &n);
	if (n < 1 || n > MAX_SIZE) {
		fprintf(stderr, "Improper value of n.\n");
		exit(EXIT_FAILURE);
	}
	
	/* Randomly generate number */
	for (i = 0; i < n; i++) {
		list[i] = rand() % 100; // 0 ~ 99
		printf("%d ", list[i]);
	}
	
	/* Sort */
	sort(list, n);
	
	/* Output */
	printf("\nSorted array:\n");
	for(i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	putchar('\n');
	
	return 0;
}
#endif
