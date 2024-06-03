#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q)
{
    q->front = q->rear = -1;
}

int isFull(Queue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }
    q->data[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", q->data[q->front]);
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }
}

void traverse(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    int i = q->front;
    while (1)
    {
        printf("%d ", q->data[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void clearInputBuffer()
{
    while (getchar() != '\n')
        ;
}

int main()
{
    Queue q;
    initializeQueue(&q);
    int choice, value;

    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            if (scanf("%d", &value) != 1)
            {
                clearInputBuffer();
                printf("Invalid input. Please enter a number.\n");
                continue;
            }
            enqueue(&q, value);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            traverse(&q);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
