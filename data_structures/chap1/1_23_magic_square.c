#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15 /* Max size of square */

void magic_square(const int size, int square[size][size]);
void print(const int size, 0int square[size][size]);

/* Main */
int main(void)
{
	int square[MAX_SIZE][MAX_SIZE];
	int i, j, size;
	
	/* Input */
	printf("Enter the size of  magic square: ");
	scanf("%d", &size);
	
	/* Check the size */
	if (size < 1 || size > MAX_SIZE) {
		fprintf(stderr, "Error, size is out of range.\n");
		exit(EXIT_FAILURE);
	} else if (!(size % 2)) {
		fprintf(stderr, "Error, size has to be an odd number.\n");
		exit(EXIT_FAILURE);		
	}
	
	/* Create an all-zero square */
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			square[i][j] = 0;
		}
	}
	
	/* Magic square */
	magic_square(size, square);
	
	/* Output */
	printf("The magic square of size %d:\n\n", size);
	print(size, square);
	
	return 0;
}

/* Magic square */
void magic_square(const int size, int square[MAX_SIZE][MAX_SIZE])
{
	int row, col;
	int i = 0;
	int j = (size + 1) / 2 - 1;
	int count = 1; // 1~size^2
	
	square[i][j] = count; // middle of the first row
	for (count = 2; count <= size * size; count++) {
		row = (i - 1 < 0) ? (size - 1) : (i - 1); // up
		col = (j - 1 < 0) ? (size - 1) : (j - 1); // left
		if (square[row][col]) { // if occupied
			i = (i + 1) % size; //down
		} else { // if empty
			i = row;
			j = col;
		}
		square[i][j] = count;
	}
}

/* Print a square */
void print(const int size, int square[MAX_SIZE][MAX_SIZE])
{
	int i, j;
	
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%5d", square[i][j]);
		}
		printf("\n");
	}
}