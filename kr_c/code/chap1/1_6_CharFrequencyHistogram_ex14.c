#include <stdio.h>

#define ASCII_SIZE 128

/* print the "vertical" histogram of the frequency of characters in inputs */
/* Test input: Hi, my name is Jack. Can u come to my restaurant to celebrate the Chinese new year with my? */
int main()
{
	int c, i, j, max;
	int frequency[ASCII_SIZE]; // ascii table size
	
	for (i = 0; i < ASCII_SIZE; i++)
		frequency[i] = 0;
	
	while ((c = getchar()) != EOF)
		++frequency[c];

	/* print vertical histogram */
	max = 0;
	for (i = 0; i < ASCII_SIZE; i++)
		if (frequency[i] > max)
			max = frequency[i];
	
	for (i = max; i >0; i--) {
		for (j = 0; j < ASCII_SIZE; j++) {
			if (frequency[j] >= i)
				printf("X");
			else if (frequency[j] != 0)
				printf(" ");
		}
		printf("\n");
	}
	
	/* print index */
	for (i = 0; i < ASCII_SIZE; i++)
		if (frequency[i] != 0)
			printf("-");
	printf("\n");
	
	for (i = 0; i < ASCII_SIZE; i++)
		if (frequency[i] != 0)
			if (i == ' '|| i == '\t' || i == '\n') // space, tab, newline print as '?' to keep beautiful
				printf("?");
			else
				printf("%c", i);
	printf("\n");
	
	return 0;
}