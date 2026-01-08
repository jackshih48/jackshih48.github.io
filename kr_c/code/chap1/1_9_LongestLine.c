#include <stdio.h>

#define MAXLINE 1000 // Maximum input line length

int getline(char line[], int maxline);
void copy(char to[], char from[]);

// Print the longest input line
int main(void) {
	int len; // Current line length
	int max = 0; // Maximum line length so far
	char line[MAXLINE]; // Current line
	char longest[MAXLINE]; // Longest line so far
	
	while ((len = getline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
		
	if (max > 0) { // If there was a line 
		printf("%s", longest);
	}
	
	return 0;
}

// getline: Read a line and return length
int getline(char line[], int maxline) {
	int c; // Input character
	int i; // Index of array
	
	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
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
void copy(char to[], char from[]) {
	int i = 0; // Index of array
	
	while ((to[i] = from[i]) != '\0') {
		i++;
	}
}