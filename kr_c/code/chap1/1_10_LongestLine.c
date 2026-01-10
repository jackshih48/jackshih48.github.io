#include <stdio.h>

#define MAXLINE 1000 // Maximum input line length

int max = 0; // Maximum line length so far
char line[MAXLINE]; // Current line
char longest[MAXLINE]; // Longest line so far

int getline(void);
void copy(void);

// Print the longest input line; specialized version
int main(void) {
	int len; // Current line length
	extern int max;
	extern char longest[];
	
	while ((len = getline()) > 0) {
		if (len > max) {
			max = len;
			copy();
		}
	}
		
	if (max > 0) { // If there was a line 
		printf("%s", longest);
	}
	
	return 0;
}

// getline: Read a line and return length
int getline(void) {
	int c; // Input character
	int i; // Index of array
	
	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		line[i] = c;
	}
	
	if (c == '\n') {
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	
	return i;
}

// copy: Copy a string 'from' into 'to'
void copy(void) {
	int i = 0; // Index of array
	extern char line[];
	extern char longest[];
	
	while ((longest[i] = line[i]) != '\0') {
		i++;
	}
}