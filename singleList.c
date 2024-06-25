#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL; // Global variable to store the head of the linked list

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning\n", value);
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d inserted at the end\n", value);
}

// Function to delete a node from the beginning of the linked list
void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning\n");
}

// Function to traverse and display all elements of the linked list
void traverse()
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked list elements: ");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the linked list
void search(int value)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node *temp = head;
    int position = 0;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("%d found at position %d\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("%d not found in the linked list\n", value);
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Traverse\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at beginning: ");
            if (scanf("%d", &value) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n')
                    ; // Clear input buffer
                continue;
            }
            insertAtBeginning(value);
            break;
        case 2:
            printf("Enter value to insert at end: ");
            if (scanf("%d", &value) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n')
                    ; // Clear input buffer
                continue;
            }
            insertAtEnd(value);
            break;
        case 3:
            deleteFromBeginning();
            break;
        case 4:
            traverse();
            break;
        case 5:
            printf("Enter value to search: ");
            if (scanf("%d", &value) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n')
                    ; // Clear input buffer
                continue;
            }
            search(value);
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
