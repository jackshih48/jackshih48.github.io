#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void strnins(char *a, char *b, int i);

int main(void)
{
	char a[MAX_SIZE] = "amobile";
	char b[MAX_SIZE] = "uto";
	
	strnins(a, b, 1); // inset "uto" into "amobile" at position 1
	printf("a:%s\nb:%s\n", a, b);
	return 0;
}

/* insert string b into string a at position i */
void strnins(char *a, char *b, int i)
{
	char string[MAX_SIZE];
	
	strncpy(string, a, i);
	string[i] = '\0';
	strcat(string, b);
	strcat(string, (a+i));
	strcpy(a, string);
}