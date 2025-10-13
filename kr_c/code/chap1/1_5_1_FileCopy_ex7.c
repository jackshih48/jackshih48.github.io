# include <stdio.h>

int main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		putchar(c);
		printf("\tgetchar()!=EOF:%d\tEOF:%d\n", c != EOF, EOF); /* Using c except getchar(), to avoid eat character here */
	}
	
	return 0;
}