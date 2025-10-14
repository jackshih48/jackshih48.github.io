#include <stdio.h>

#define MAX_WORD_LENGTH 10 /* count numbers of word with length 1~9 and greater than 9 */
#define IN 1 /* state of inside a word */
#define OUT 0 /* state of outside a word */

/* print the "vertical" histogram of the lengths of words in inputs */
/* Test input: Hi, my name is Jack. Can u come to my restaurant to celebrate the Chinese new year with my? */
int main()
{
	int c, i, j, state, word_counting, max;
	int nwords[MAX_WORD_LENGTH];
	
	state = word_counting = 0;
	for (i = 0; i < MAX_WORD_LENGTH; i++)
		nwords[i] = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				state = OUT;
				if (word_counting < MAX_WORD_LENGTH)
					++nwords[word_counting - 1];
				else
					++nwords[MAX_WORD_LENGTH - 1];
				
				word_counting = 0;
			}
		} else {
			state = IN;
			++word_counting;
		}
	}
	if (state == IN) {
		if (word_counting < MAX_WORD_LENGTH)
			++nwords[word_counting - 1];
		else
			++nwords[MAX_WORD_LENGTH - 1];
	}

	/* print vertical histogram */
	max = 0;
	for (i = 0; i < MAX_WORD_LENGTH; i++)
		if (nwords[i] > max)
			max = nwords[i];
		
	for (i = max; i >0; i--) {
		for (j = 0; j < MAX_WORD_LENGTH; j++) {
			if (nwords[j] >= i)
				printf("X");
			else
				printf(" ");
		}
		printf("\n");
	}
	
	/* print index */
	for (i = 0; i < MAX_WORD_LENGTH; i++)
		printf("-");
	printf("\n");
	
	for (i = 0; i < MAX_WORD_LENGTH; i++)
		printf("%d", i + 1); // greater than 9 print as 10
	printf("\n");
	
	return 0;
}