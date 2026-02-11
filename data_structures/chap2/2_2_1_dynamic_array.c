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

void print_int_array(const int *list, int size);

int main(void)
{
	int n, *list;
	
	printf("Enter the number of numbers to generate: ");
	scanf("%d", &n);
	
	if( n < 1 ) {
		fprintf(stderr, "Improper value of n.\n");
		exit(EXIT_FAILURE);
	}
	
	MALLOC(list, n * sizeof(int)); // Easy ver: list = malloc(n * sizeof(int))
	print_int_array(list, n);
	
	for (int i = 0; i < n; i++) {
        list[i] = rand() % 100;   // 0~99
    }
	print_int_array(list, n);
	
	free(list);
	return 0;
}

void print_int_array(const int *list, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}
	putchar('\n');
}