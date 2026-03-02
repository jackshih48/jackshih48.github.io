/* Represent, transpose and multiplication for sparse matrix */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100
#define MAX_COL 100

struct term { // nonzero entry of sparse matrix
	int col;
	int row;
	int value;
};

void printTriple(struct term *a);
void printMatrix(struct term *a);
void transpose(struct term *a, struct term *b);
void fastTranspose(struct term *a, struct term *b);
void mmult(struct term *a, struct term *b, struct term *c);

int main(void)
{
	int rows, cols, nonzeros;
	int row, col, value;
	struct term a[MAX_TERMS];
	struct term b[MAX_TERMS];
	struct term c[MAX_TERMS];
	struct term d[MAX_TERMS];
	
	// a[0] store the info of sparse matrix
	printf("Enter the number of nonzero entries of your sparse matrix: ");
	scanf(" %d", &nonzeros);
	printf("Enter the number of rows of your sparse matrix: ");
	scanf(" %d", &rows);
	printf("Enter the number of columns of your sparse matrix: ");
	scanf(" %d", &cols);
	a[0] = (struct term){.col = cols, .row = rows, .value = nonzeros};
	
	// a[1]~a[nonzero] store each entry(the col, row, and value) of sparse matrix 
	for (int i = 1; i <= nonzeros; i++) {
		printf("Enter the row index of this nonzero entry(%dth): ", i);
		scanf(" %d", &row);
		printf("Enter the column index of this nonzero entry(%dth): ", i);
		scanf(" %d", &col);
		printf("Enter the value of this nonzero entry(%dth): ", i);
		scanf(" %d", &value);
		a[i] = (struct term){.col = col, .row = row, .value = value};
	}
	
	// print a, a^T, a*a^T
	transpose(a, b);
	fastTranspose(b, c); // c = a, but in correct order of triples
	mmult(c, b, d);// d = c*b
	//printTriple(a);
	//printTriple(b);
	//printTriple(c);
	
	printf("A:");
	printMatrix(a);
	printf("A^T:");
	printMatrix(b);
	printf("A(A^T):");
	printMatrix(d);
	
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
					b[currentb] = (struct term){.col = a[j].row, .row = a[j].col, .value = a[j].value};
					currentb++;
				}
			}
		}
	}
}

void fastTranspose(struct term *a, struct term *b) // Faster algorithm
{
	int i, j;
	int rowterms[MAX_COL]; // Number of nonzero entries in each column of original matrix
	int startingPos[MAX_COL]; // Construct staring table
	
	b[0] = (struct term){.col = a[0].row, .row = a[0].col, .value = a[0].value};
	if (a[0].value > 0) { // Nonzero matrix
		for (i = 0; i < a[0].col; i++) {
			rowterms[i] = 0;
		}
		
		for (i = 1; i <= a[0].value; i++) {
			rowterms[a[i].col]++;
		}
		
		startingPos[0] = 1;
		for (i = 1; i < a[0].col; i++) {
			startingPos[i] = startingPos[i-1] + rowterms[i-1]; 
		}
		
		for (i = 1; i <= a[0].value; i++) {
			j = startingPos[a[i].col];
			startingPos[a[i].col]++;
			b[j] = (struct term){.col = a[i].row, .row = a[i].col, .value = a[i].value};
		}
	}
}


/* mmult Algorithm Pseudocode:
bT = b^T
for each row r in a:
  for each row k in bT:		// = for each col k in b
	 sum = dot(a_row(r), bT_row(k))		// using switch merge
	 if sum != 0: store (r,k,sum) in c
*/
void mmult(struct term *a, struct term *b, struct term *c)
{
	struct term bT[MAX_TERMS]; // b^T
	int newc = 1; // Index for add a new term of c
	
	if (a[0].col != b[0].row) {
		fprintf(stderr, "Size is wrong.\n");
		exit(EXIT_FAILURE);
	}
	
	c[0] = (struct term){.col = b[0].col, .row = a[0].row, .value = 0};
	
	fastTranspose(b, bT);
	for (int r = 0; r < a[0].row; r++) {
		// 找出a中位於row r的entries範圍
		int aStart = -1, aEnd = -1;
		for (int i = 1; i <= a[0].value; i++) {
			if (a[i].row == r) {
				if (aStart == -1) { // 第一次找到
					aStart = i;
				}
				aEnd = i; // 每一次找到
			}
		}
		if (aStart == -1) { // 此row全0，直接跳下一個row
			continue;
		}
		
		for (int k = 0; k < b[0].col; k++) {
			// 找出b中位於col k的entries範圍
			int bStart = -1, bEnd = -1;
			for (int j = 1; j <= bT[0].value; j++) {
				if (bT[j].row == k) {
					if (bStart == -1) {
						bStart = j;
					}
					bEnd = j;
				}
			}
			if (bStart == -1) {
				continue;
			}
			
			// Dot product
            int sum = 0;
            int i = aStart, j = bStart;
            while (i <= aEnd && j <= bEnd) {
                if (a[i].col < bT[j].col)
                    i++;
                else if (a[i].col == bT[j].col)
                    sum += a[i++].value * bT[j++].value;
                else // a[i].col > bT[j].col
                    j++;
            }
			
			// Store
            if (sum != 0) {
                c[newc++] = (struct term){.row = r, .col = k, .value = sum};
                c[0].value++;
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
