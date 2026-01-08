#include <stdio.h>

#define MAXLINE 1000 // Maximum input line length
#define TRESHOLD 30 // Length of line we want to print

int getLine(char line[], int maxline);
void printLine(char line[]);

// Print the input lines with length over TRESHOLD
int main(void) {
	int len; // Current line length
	char line[MAXLINE]; // Current line
	
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > TRESHOLD) {
			printLine(line);
		}
	}
	
	return 0;
}

// getline: Read a line and return length
int getLine(char line[], int maxline) {
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

// printLine: Print a line
void printLine(char line[]) {
	int i = 0; // Index of array
	
	while (line[i] != '\0') {
		putchar(line[i]);
		i++;
	}
}