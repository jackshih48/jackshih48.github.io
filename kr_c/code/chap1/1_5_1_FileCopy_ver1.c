#include <stdio.h>

/* copy input to output */

int main()
{
	int c;
	// char c;
	
	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
	return 0;
}