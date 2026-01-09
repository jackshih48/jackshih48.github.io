#include <stdio.h>

#define MAXLINE 1000 // Max length of a line

int getLine(char line[], int line_length);
int removeBlank(char line[], int line_length);

// Remove trailing blanks and tabs of each line and delete the blank lines
int main(void) {
	char line[MAXLINE]; // Input line
	int line_length; // Input line length
	
	while ((line_length = getLine(line, MAXLINE)) > 0) {
		if (removeBlank(line, line_length) > 0) {
			printf("%s", line);	
		}
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

// removeBlank: Remove 'tailing blanks' and tabs of each line
int removeBlank(char line[], int line_length) {
	int i = line_length - 1; // Index of line tail
	
    if (i >= 0 && line[i] == '\0') {
        i--;
    }
	
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')) {
		i--;
	}
	
    if (i < 0) {
        line[0] = '\0';
        return 0;
    }
	
	line[i + 1] = '\n';
	line[i + 2] = '\0';
	
	return i+1;
}
