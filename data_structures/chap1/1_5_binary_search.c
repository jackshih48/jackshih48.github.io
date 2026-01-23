#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)

void sort (int list[], int n);
int binsearch(int list[], int target, int left, int right);
int binsearchr(int list[], int target, int left, int right);

/* Main */
int main(void)
{
	int i, n, target, pos, pos2;
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
	printf("\nSorted array:\n");
	for(i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	putchar('\n');
	
	/* Binary search */
	printf("Enter the number you to find: ");
	scanf("%d", &target);
	pos = binsearch(list, target, 0, n-1);
	pos2 = binsearchr(list, target, 0, n-1);
	if (pos == -1) {
		printf("Cannot find the target.\n");
	} else {
		printf("The position of target is %d. (Iterative ver.)\n", pos);
		printf("The position of target is %d. (Recursive ver.)\n", pos2);
	}
	
	return 0;
}

/* Selection sort: Order a list from min to max */
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

/* Binary search (iteration ver.): Return the position of target (if find) in an ordered list, 
	or return -1. */
int binsearch(int list[], int target, int left, int right)
{
	int middle;
	
	while (left <= right) {
		middle = left + (right - left) / 2; // middle = (left + right)/2, avoid overflow
		switch (COMPARE(list[middle], target)) {
			case -1:
				left = middle + 1;
				break;
			case 0:
				return middle;
			case 1:
				right = middle - 1;
				break;
		}
	}
	
	return -1;
}

/* Binary search (recursive ver.) */
int binsearchr(int list[], int target, int left, int right)
{
	int middle;
	
	if (left <= right) {
		middle = left + (right - left) / 2;
		switch (COMPARE(list[middle], target)) {
			case -1:
				return binsearchr(list, target, middle + 1, right);
			case 0:
				return middle;
			case 1:
				return binsearchr(list, target, left, middle - 1);
		}
	}
	
	return -1;
}