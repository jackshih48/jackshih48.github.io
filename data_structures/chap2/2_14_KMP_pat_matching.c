/* KMP algorithm for "pattern matching in strings" with O(n+m) */
/* https://www.youtube.com/watch?v=af1oqpnH1vA and jackshih2262 comment */

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int kmp(char *text, char *pattern);
void createNext(int *next, char *pattern);

int main(void)
{
	char text[MAX_SIZE] = "abababcaa";
	char pattern[MAX_SIZE] = "ababc";
	int pos;
	
	pos = kmp(text, pattern);
	printf("Text:\"%s\" \nPatt:\"%s\" \nThe first position of pattern in text is %d.\n", text, pattern, pos);
	return 0;
}

int kmp(char *text, char *pattern)
{
	int n = strlen(text);
	int m = strlen(pattern);
	int next[m];
	int i = 0;
	int j = 0;
	
	createNext(next, pattern);
	while (i < n) { // Note that i never back
		if (text[i] == pattern[j]) {
			if (j == m - 1) { // Match
				return i - m + 1; // Return the staring position
			}
			i++;
			j++;
		} else { // Miss match 
			if (j == 0) {
				i++;
			} else {
				j = next[j - 1];
			}
		}
	}
	return -1;
}

// eg. next of "ababc" =  [0 0 1 2 0]
void createNext(int *next, char *pattern)
{
	int m = strlen(pattern);
	int len = 0; // Longest prefix==suffix length so far
	int i = 1;
	
	next[0] = 0;
	while (i < m) { // similar logic of kmp function
        if (pattern[i] == pattern[len]) {
            len++;
            next[i] = len;
            i++;
        } else {
            if (len == 0) {
                next[i] = 0;
                i++;
            } else {
                len = next[len - 1];
            }
        }
	}
}