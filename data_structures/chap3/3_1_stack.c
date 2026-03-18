/* Using stack to implement parentheses balance check */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// stack
struct Stack {
	char data[MAX];
	int top;
};

int check(char *str);
void initStack(struct Stack *s);
void push(struct Stack *s, char c);
char pop(struct Stack *s);
char peek(struct Stack *s); // When have (),[],{}, peek can see the top first then determine to pop or not
int isFull(struct Stack *s);
int isEmpty(struct Stack *s);

int main(void)
{
	char *str[] = {
		"((()))",
		"(()))(",
		"((())))"
	};
	
	int n = 3;
	for (int i = 0; i < n; i++) {
		printf("%s is %s \n", str[i], check(str[i]) ? "balanced" : "not balanced");
	}
	return 0;
}

int check(char *str)
{
	struct Stack s;
	initStack(&s);
	
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == '(') {
			push(&s, str[i]);
		} else if (str[i] == ')') {
			if (pop(&s) == '\0') {
				return 0;
			}
		}
		
		i++;
	}
	
	return isEmpty(&s);
}

void initStack(struct Stack *s)
{
	s->top = -1;
}

void push(struct Stack *s, char c)
{
	if (isFull(s)) {
		fprintf(stderr, "Stack overflow\n");
		exit(1);
	}
	s->data[++(s->top)] = c;
}

char pop(struct Stack *s)
{
	if (isEmpty(s)) {
		return '\0';
	}
	return s->data[(s->top)--];
}

char peek(struct Stack *s)
{
	if (isEmpty(s)) {
		return '\0';
	}
	return s->data[s->top];
}


int isFull(struct Stack *s)
{
	return s->top >= MAX - 1;
}

int isEmpty(struct Stack *s)
{
	return s->top < 0;
}