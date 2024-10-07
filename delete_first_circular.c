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
    if (head == NULL) return; // Check for empty list

    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Function to delete the node at the beginning of the circular linked list
void deleteAtBeginning(struct Node **head)
{
    if (*head == NULL) return; // Check if list is empty

    struct Node *temp = *head;

    // If there's only one node in the list
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *last = *head;
        // Find the last node
        while (last->next != *head)
        {
            last = last->next;
        }
        // Update the head and the last node's next
        *head = (*head)->next;
        last->next = *head;

        // Free the old head
        free(temp);
    }
}

int main()
{
    // Creating nodes
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (head == NULL || second == NULL || third == NULL || fourth == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Linked first and second nodes
    head->data = 7;
    head->next = second;

    // Linked second and third nodes
    second->data = 9;
    second->next = third;

    // Linked third and fourth nodes
    third->data = 55;
    third->next = fourth;

    // Terminate list after fourth node
    fourth->data = 110;
    fourth->next = head;

    // Print the original list
    printf("Original list:\n");
    linkedListTraversal(head);

    // Delete node at the beginning
    deleteAtBeginning(&head);

    // Print the modified list
    printf("List after deletion:\n");
    linkedListTraversal(head);

    // Free remaining nodes (in case there are any)
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
