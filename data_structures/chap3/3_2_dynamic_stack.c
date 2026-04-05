/* Using dynamic stack to implement '(' & ')' balance check */

#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 4

// dynamic stack
struct Stack {
	char *data;
	int top;
	int capacity;
};

int check(char *str);
void initStack(struct Stack *s);
void push(struct Stack *s, char c);
char pop(struct Stack *s);
char peek(struct Stack *s); // When have (),[],{}, peek can see the top first then determine to pop or not
int isFull(struct Stack *s);
int isEmpty(struct Stack *s);
void expandStack(struct Stack *s);
void freeStack(struct Stack *s);

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
	
    int result = isEmpty(&s);
    freeStack(&s);
    return result;
}

void initStack(struct Stack *s)
{
	s->top = -1;
	s->capacity = INIT_CAPACITY;
	s->data = malloc(INIT_CAPACITY * sizeof(s->data));
    
	if (s->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

void expandStack(struct Stack *s)
{
    s->capacity *= 2;
    char *newData = realloc(s->data, s->capacity * sizeof(s->data));

    if (newData == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(s->data);
        exit(1);
    }

    s->data = newData;
}

void push(struct Stack *s, char c)
{
	if (isFull(s)) { // When stack is fulled, doubled the capacity
		expandStack(s);
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
	return s->top >= s->capacity - 1;
}

int isEmpty(struct Stack *s)
{
	return s->top < 0;
}

void freeStack(struct Stack *s)
{
    free(s->data);
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}