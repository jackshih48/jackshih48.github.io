#include <stdio.h>

#define MAXLINE 1000 // Maximum input line length
#define TABSTOP 8 // Fixed tab stops

int getline(char line[]);
void detab(char line[]);

int main(void) {
	char line[MAXLINE]; // Input line
	
	while (getline(line) > 0) {
		detab(line);
	}
	return 0;
}

// getline: Read a line and return length
int getline(char line[]) {
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

// detab: Replace tab with blanks, the number of blanks achieve next tabstop
void detab(char line[]) {
	int c, i, j;
	int count = 0; // TABSTOP - the number of blanks achieve next tabstop
	
	for (i = 0; i < sizeof(line); i++) {
		if ((c = line[i]) != '\t') {
			putchar(c);
			count++;
		} else if ((c = line[i]) != '\t'){
			for (j = 0; j < TABSTOP - count; j++) {
				putchar(' ');
			}
			count = 0;
		}
		
		if (count == TABSTOP) {
			count = 0;
		}
	}
}