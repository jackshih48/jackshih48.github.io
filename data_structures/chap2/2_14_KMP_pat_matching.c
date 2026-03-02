/* KMP algorithm for "pattern matching in strings" with O(n+m) */
/* https://www.youtube.com/watch?v=af1oqpnH1vA */

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000;

int kmp(char *text, char *pattern);

int main(void)
{
	char text[MAX_SIZE] = "abababcaa";
	char pattern[MAX_SIZE] = "abc";
	int pos;
	
	pos = kmp(text, pattern);
	printf("The first position of pattern in text is %d", pos);
	return 0;
}