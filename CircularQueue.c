#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int data[MAX];
    int front, rear;
} CircularQueue;

void initializeQueue(CircularQueue *q)
{
    q->front = q->rear = -1;
}

int isFull(CircularQueue *q)
{
    return q->front == (q->rear + 1) % MAX;
}

int isEmpty(CircularQueue *q)
{
    return q->front == -1;
}

void enqueue(CircularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

void dequeue(CircularQueue *q)
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

void traverse(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->front;; i = (i + 1) % MAX)
    {
        printf("%d ", q->data[i]);
        if (i == q->rear)
            break;
    }
    printf("\n");
}

int main()
{
    CircularQueue q;
    initializeQueue(&q);
    int choice, value;

    while (1)
    {
        printf("\nQueue Operations:\n1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n')
                    ;

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
