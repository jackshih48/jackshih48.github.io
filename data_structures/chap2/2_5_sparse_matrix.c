#include <stdio.h>

#define MAX_TERMS 100

struct term {
	int col;
	int row;
	int value;
};

void printTriple(struct term *a);
void printMatrix(struct term *a);
void transpose(struct term *a, struct term *b);

int main(void)
{
	int rows, cols, nonzeros;
	int row, col, value;
	struct term a[MAX_TERMS];
	struct term b[MAX_TERMS];
	
	// a[0] store the info of sparse matrix
	printf("Enter the number of nonzero entries of your sparse matrix: ");
	scanf(" %d", &nonzeros);
	printf("Enter the number of rows of your sparse matrix: ");
	scanf(" %d", &rows);
	printf("Enter the number of columns of your sparse matrix: ");
	scanf(" %d", &cols);
	a[0] = (struct term){cols, rows, nonzeros};
	
	// a[1]~a[nonzero] store each entry(the col, row, and value) of sparse matrix 
	for (int i = 1; i <= nonzeros; i++) {
		printf("Enter the row index of this nonzero entry(%dth): ", i);
		scanf(" %d", &row);
		printf("Enter the column index of this nonzero entry(%dth): ", i);
		scanf(" %d", &col);
		printf("Enter the value of this nonzero entry(%dth): ", i);
		scanf(" %d", &value);
		a[i] = (struct term){col, row, value};
	}
	
	transpose(a, b);
	printTriple(a);
	printTriple(b);
	printMatrix(a);
	printMatrix(b);
	
	return 0;
}

void transpose(struct term *a, struct term *b) // b is the transpose of a
{
	int currentb = 1;
	
	b[0] = (struct term){a[0].row, a[0].col, a[0].value};
	if (a[0].value > 0) { // Nonzero matrix
		for (int i = 0; i < a[0].col; i++) {
			for (int j = 1; j <= a[0].value; j++) { // 鎖定col，遍歷所有nonzero entries
				if (a[j].col == i) {
					b[currentb] = (struct term){a[j].row, a[j].col, a[j].value};
					currentb++;
				}
			}
		}
	}
}

void printTriple(struct term *a)
{
	printf("\nrow\tcol\tvalue\n");
	for (int i = 1; i <= a[0].value; i++) {
		printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
	}
}

void printMatrix(struct term *a)
{
	int b[a[0].row][a[0].col];
	
	for (int i = 0; i < a[0].row; i++) {
		for (int j = 0; j < a[0].col; j++) {
			b[i][j] = 0;
		}
	}

	for (int i = 1; i <= a[0].value; i++) {
		b[a[i].row][a[i].col] = a[i].value;
	}
	
	printf("\n");
	for (int i = 0; i < a[0].row; i++) {
		for (int j = 0; j < a[0].col; j++) {
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
