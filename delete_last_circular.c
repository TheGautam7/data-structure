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
    struct Node *ptr = head;
    if (head != NULL)
    {
        do
        {
            printf("Element is %d\n", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

// Function to delete the last node from a circular linked list
void deleteLastNode(struct Node *head)
{
    // Check if the list is empty or has only one node
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    // If there's only one node
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    // Initialize pointers to traverse the list
    struct Node *temp = head;
    struct Node *prev = NULL;

    // Traverse the list to find the second-to-last node
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    // Now temp is the last node and prev is the second-to-last node
    prev->next = head;
    free(temp);
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

    // linked first and second nodes
    head->data = 7;
    head->next = second;

    // linked second and third nodes
    second->data = 9;
    second->next = third;

    // linked third and fourth nodes
    third->data = 55;
    third->next = fourth;

    // terminate list after fourth node
    fourth->data = 110;
    fourth->next = head;

    printf("Original list:\n");
    linkedListTraversal(head);

    // Delete the last node
    deleteLastNode(head);

    printf("List after deleting the last node:\n");
    linkedListTraversal(head);

    return 0;
}
