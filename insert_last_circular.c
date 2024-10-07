#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to traverse and print the linked list
void linkedListTraversal(struct Node *head)
{
    if (head == NULL) return; // Handle empty list

    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Function to insert a new node at the end of the circular linked list
void insertAtEnd(struct Node *head, int newData)
{
    if (head == NULL) return; // Handle empty list

    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    
    // Traverse to the last node
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
    newNode->next = head;
}

int main()
{
    // Creating nodes
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 9;
    second->next = third;

    // Link third and fourth nodes
    third->data = 55;
    third->next = fourth;

    // Terminate list after fourth node
    fourth->data = 110;
    fourth->next = head;

    // Insert new node at the end
    insertAtEnd(head, 999);

    // Traverse and print the linked list
    linkedListTraversal(head);

    return 0;
}
