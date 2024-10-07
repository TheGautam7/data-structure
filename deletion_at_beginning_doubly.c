#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev; // Previous pointer
    struct Node *next; // Next pointer
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// CASE 1: DeleteFirst for Doubly Linked List

struct Node *DeleteFirst(struct Node *head)
{
    if (head == NULL)
    {
        return NULL; // If the list is empty
    }

    struct Node *ptr = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL; // Set the new head's prev to NULL
    }

    free(ptr);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocating memory for nodes in the doubly linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Setting up the doubly linked list
    head->data = 4;
    head->prev = NULL; // Head prev is NULL
    head->next = second;

    second->data = 3;
    second->prev = head;
    second->next = third;

    third->data = 8;
    third->prev = second;
    third->next = fourth;

    fourth->data = 1;
    fourth->prev = third;
    fourth->next = NULL; // Last node next is NULL

    printf("Before deletion:\n");
    LinkedListTraversal(head);

    head = DeleteFirst(head); // Deleting the first element

    printf("After deletion:\n");
    LinkedListTraversal(head);

    return 0;
}
