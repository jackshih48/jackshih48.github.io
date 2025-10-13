#include <stdio.h>

/* compact style for read data */

int main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		putchar(c);
	}
	
	return 0;
}