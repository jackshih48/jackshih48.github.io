/* Timing the worst case of selection sort */

#include <stdio.h>
#include <time.h>
#include "selectionSort.h"

#define MAX_SIZE 1000

int main(void)
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	
	printf("     n\t repetitions\t time(sec)\n");
	for (n = 0; n <= 1000; n += step) {
		long repetitions = 0;
		clock_t start = clock();
		
		do {
			repetitions++;
			for (i = 0; i < n; i++) {
				a[i] = n - i; // worst case of selection sort 
			}
			sort(a, n); // selection sort
		} while (clock() - start < CLOCKS_PER_SEC); // repeat enough time
		
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration /= repetitions;
		printf("%6d\t %9d\t %f\n", n, repetitions, duration);
		
		if (n == 100) {
			step = 100;
		}
	}
	
	return 0;
}