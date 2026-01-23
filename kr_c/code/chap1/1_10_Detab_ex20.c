#include <stdio.h>

#define MAXLINE 1000 // Maximum input line length
#define TABSTOP 8 // Fixed tab stops

char line[MAXLINE]; // Input line
	
int getline(void);
void detab(void);
void print_visible(void);

int main(void) {
	while (getline() > 0) {
		/*
		printf("Visible: ");
		print_visible();
		printf("Detabed: ");
		*/
		detab(); // Execute in terminal: a.exe < 1_10_Detab_ex20_in.txt > 1_10_Detab_ex20_out.txt
	}
	
	return 0;
}

// getline: Read a line and return length
int getline(void) {
	extern char line[MAXLINE];
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

// detab: Replace tab with spaces, the number of spaces achieve next tabstop
void detab(void) {
	extern char line[MAXLINE];
	int i;
	int space; // The number of spaces
	int col = 0; // Current column
	
	for (i = 0; line[i] != '\0'; i++) {
		if (line[i] != '\t') {
			putchar(line[i]);
			if (line[i] == '\n')
                col = 0;
            else
                col++;
		} else { // line[i] == '\t'
			space = TABSTOP - col % TABSTOP;
			while (space-- > 0) {
				putchar(' ');
				col++;
			}
		}
	}
}

void print_visible(void) {
	extern char line[MAXLINE];
	for (int i = 0; line[i] != '\0'; i++) {
		 if (line[i] == ' ') {
			 putchar('.');
		 } else if (line[i] == '\t') {
			 putchar('>');
		 } else {
			 putchar(line[i]);
		 }
	}
}