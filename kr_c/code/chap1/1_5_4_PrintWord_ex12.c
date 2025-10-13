#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* Print its input one word per line */
int main()
{
	int c, state;
	
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				state = OUT;
				putchar('\n');
			}
		} else {
			state = IN;
			putchar(c);
		}
	}
	if (state == IN)
		putchar('\n');
	
	return 0;
}