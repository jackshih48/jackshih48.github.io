#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
	int data[MAX];
	int front;
	int rear;
};

void initQ(struct Queue *q);
void pushQ(struct Queue *q, int a);
int popQ(struct Queue *q);
void printQ(struct Queue *q);
int peek(struct Queue *q);
int isFull(struct Queue *q);
int isEmpty(struct Queue *q);

int main(void)
{
	struct Queue q;
	
	init(&q);
	
	pushQ(&q, 10);
	pushQ(&q, 20);
	pushQ(&q, 30);
	printQ(&q);
	
    printf("Dequeue: %d\n", popQ(&q));
    printQ(&q);

    popQ(&q, 40);
    popQ(&q, 50);
    printQ(&q);

    printf("Peek: %d\n", peek(&q));
	
	return 0;
}

void initQ(struct Queue *q)
{
	q->front = -1;
	q->rear = -1;
}

void pushQ(struct Queue *q, int a)
{	
	if (isFull(q)) {
		fprintf(stderr, "Queue is full\n");
		exit(1);
	}
	q->data[++(q->rear)] = a;
}

int popQ(struct Queue *q)
{
	if (isEmpty(q)) {
		fprintf(stderr, "Queue is empty\n");
		return -1;
	}
	
	return q->data[++(q->front)];
}

void printQ(struct Queue *q)
{
    printf("Queue: ");

    if (isEmpty(q)) {
        printf("(empty)\n");
        return;
    }

    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");

    printf("front = %d, rear = %d\n", q->front, q->rear);
}

int peek(struct Queue *q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->data[q->front + 1];
}	

int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

int isFull(struct Queue *q)
{
    return q->rear == MAX - 1;
}