#include <stdio.h>

/* copy input to output, replace tab by \t */
int main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		}
		if (c != '\t')
			putchar(c);
	}
	
	return 0;
}