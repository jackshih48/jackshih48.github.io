#include <stdio.h>

#define MAXLINE 1000 // Max length of a line

int getLine(char line[], int line_length);
void reverseLine(char to[], char from[], int line_length);

// Reverse Line
int main(void) {
	char line[MAXLINE]; // Input line
	char reverse[MAXLINE]; // Reverse line
	int line_length; // Input line length
	
	while ((line_length = getLine(line, MAXLINE)) > 0) {
		reverseLine(reverse, line, line_length);
		printf("%s", reverse);	
	}
	
	return 0;
}

// getline: Read a line and return length
int getLine(char line[], int line_length) {
	int c; // Input character
	int i; // Index of array
	
	for (i = 0; i < line_length - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		line[i] = c;
	}
	
	if (c == '\n') {
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	
	return i;
}

// reverseLine: Reverse a string 'from' into 'to'
void reverseLine(char to[], char from[], int line_length) {
    int end = line_length;

    if (end > 0 && from[end - 1] == '\n') {
		end--;
	}

    for (int i = 0; i < end; i++) {
        to[i] = from[end - 1 - i];
    }

    if (end < line_length && from[line_length - 1] == '\n') {
        to[end] = '\n';
        to[end + 1] = '\0';
    } else {
        to[end] = '\0';
    }
}
