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

// Function to insert a node at the beginning of the doubly linked list
struct Node *insertAtBeginning(struct Node *head, int data)
{
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Set the data for the new node
    newNode->data = data;

    // Set the next pointer of the new node to point to the current head
    newNode->next = head;

    // Set the previous pointer of the new node to NULL
    newNode->prev = NULL;

    // If the list is not empty, set the previous pointer of the current head to the new node
    if (head != NULL)
    {
        head->prev = newNode;
    }

    // Make the new node the new head of the list
    head = newNode;

    return head;
}

int main()
{
    // Creating nodes
    struct Node *head;
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
    fourth->next = NULL;  // No next node for the last node
    fourth->prev = third; // Link back to the third node

    printf("Traversal in forward direction before insertion:\n");
    LinkedListTraversal(head);

    // Insert a new node at the beginning of the doubly linked list
    head = insertAtBeginning(head, 99);

    printf("\nTraversal in forward direction after insertion at beginning:\n");
    LinkedListTraversal(head);

    printf("\nTraversal in reverse direction after insertion at beginning:\n");
    ReverseLinkedListTraversal(head);

    return 0;
}
