#include <stdio.h>

/* copy the input as output, 
	replace one or more blanks in input by a single blank in output */
int main()
{
	int c, nb;
	
	nb = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			putchar(c);
			nb = 0;
		}
		if (c == ' ')
			++nb;
		if (nb == 1)
			putchar(c);
	}
	
	return 0;
}