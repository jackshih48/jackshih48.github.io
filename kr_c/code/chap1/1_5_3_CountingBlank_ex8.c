#include <stdio.h>

/* count blanks, tabs, and newlines in input */
int main()
{
	int c, nb, nt, nl;
	
	nb = 0;
	nt = 0;
	nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nl;
	}
	printf("blank:%d tab:%d line:%d\n", nb, nt, nl);
	
	return 0;
}