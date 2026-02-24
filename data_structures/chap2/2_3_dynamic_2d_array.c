#include <stdio.h>
#include <stdlib.h>

#define MALLOC(ptr, size) \
    do { \
        (ptr) = malloc(size); \
        if (!(ptr)) { \
            fprintf(stderr, "Insufficient memory\n"); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

void print2dArray(int **array, int m, int n);
int **make2dArray(int row, int col);

int main(void)
{
	int m, n, **array;
	
	printf("Enter the row: ");
	scanf("%d", &m);
	printf("Enter the column: ");
	scanf("%d", &n);
	
	if( m < 1 || n < 1) {
		fprintf(stderr, "Improper value of size.\n");
		exit(EXIT_FAILURE);
	}
	
	array = make2dArray(m, n);
	print2dArray(array, m, n);
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] = rand() % 100;   // 0~99	
		}
    }
	print2dArray(array, m, n);
	
	free(array);
	return 0;
}

void print2dArray(int **array, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", array[i][j]);	
		}
		putchar('\n');
    }
	putchar('\n');
}

int **make2dArray(int row, int col)
{
	int **x;
	
	MALLOC(x, row * sizeof(int*));
	
	for(int i = 0; i < row; i++) {
		MALLOC(x[i], col * sizeof(int));
	}
	
	return x;
}