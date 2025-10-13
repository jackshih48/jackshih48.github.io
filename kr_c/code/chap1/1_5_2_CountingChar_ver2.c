#include <stdio.h>

/* count character in input */

int main()
{
	long nc;
	
	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%ld\n", nc);
	
	return 0;
}