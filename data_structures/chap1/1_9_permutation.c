#include <stdio.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void perm(char list[], int start, int end);
void print(const char s[]);

/* Main */
int main(void)
{
	char list[] = "123";
	int n = (int)sizeof(list) - 1; // Minus '\0'
	
	perm(list, 0, n-1);
	return 0;
}

/* Perm: Print all the permutations of the list */
void perm(char list[], int start, int end)
{
	int i, temp;
	
	if (start == end) {
		print(list);
	} else {
		for (i = start; i <= end; i++) {
			SWAP(list[start], list[i], temp);
			perm(list, start + 1, end);
			SWAP(list[start], list[i], temp);
		}
	}
}

/* Print: Print a string. Note that stdio.h already support puts(s) */
void print(const char s[])
{
	int i = 0;
	while (s[i] != '\0') {
		putchar(s[i]);
		i++;
	}
	putchar('\n');
}