#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev; // Pointer to the previous node
};

// Function to traverse and print the linked list
void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to traverse the linked list in reverse order
void ReverseLinkedListTraversal(struct Node *ptr)
{
    // Move to the end of the list
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    // Now traverse backwards
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

// Function to insert a node at the end of the doubly linked list without double pointer
void InsertAtEnd(struct Node *head, int data)
{
    // Allocate memory for the new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = head; // Start from the head

    // Set data for the new node
    newNode->data = data;
    newNode->next = NULL; // New node will be the last node, so next is NULL

    // If the linked list is empty, just return
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    // Otherwise, traverse to the end of the list
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Update the links for the new node
    last->next = newNode;
    newNode->prev = last;
}

int main()
{
    // Creating nodes
    struct Node *head = NULL;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the doubly linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;
    head->prev = NULL; // No previous node for the head

    // Link second and third nodes
    second->data = 9;
    second->next = third;
    second->prev = head; // Link back to the first node

    // Link third and fourth nodes
    third->data = 55;
    third->next = fourth;
    third->prev = second; // Link back to the second node

    // Terminate list after fourth node
    fourth->data = 110;
    fourth->next = NULL; // No next node for the last node
    fourth->prev = third; // Link back to the third node

    printf("Traversal in forward direction:\n");
    LinkedListTraversal(head);

    // Insert a new node at the end
    printf("\nInserting a new node at the end with data 200\n");
    InsertAtEnd(head, 200);

    // Traverse again after insertion
    printf("\nTraversal in forward direction after insertion:\n");
    LinkedListTraversal(head);

    printf("\nTraversal in reverse direction:\n");
    ReverseLinkedListTraversal(fourth);

    return 0;
}
