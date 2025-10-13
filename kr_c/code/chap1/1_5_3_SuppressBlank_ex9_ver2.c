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
		} else {
			if (nb == 0)
				putchar(c);
			++nb;
		}
	}
	
	return 0;
}