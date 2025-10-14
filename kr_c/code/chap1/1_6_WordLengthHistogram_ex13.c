#include <stdio.h>

#define MAX_WORD_LENGTH 10 /* count numbers of word with length 1~9 and greater than 9 */
#define IN 1 /* state of inside a word */
#define OUT 0 /* state of outside a word */

/* print the horizontal histogram of the lengths of words in inputs */
/* Test input: Hi, my name is Jack. Can u come to my restaurant to celebrate the Chinese new year with my? */
int main()
{
	int c, i, j, state, word_counting;
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

	/* print 1~9 */
	for (i = 0; i < MAX_WORD_LENGTH - 1; i++) {
		printf("%d\t|", i + 1);
		for (j = 0; j < nwords[i]; j++)
			printf("X");
		printf("\n");
	}
	
	/* print > 9 */
	printf(">%d\t|", MAX_WORD_LENGTH);
	for (j = 0; j < nwords[MAX_WORD_LENGTH - 1]; j++)
		printf("X");
	printf("\n");
	
	return 0;
}