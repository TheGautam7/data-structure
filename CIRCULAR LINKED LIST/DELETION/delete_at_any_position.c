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

// Function to delete a node at a specific position
void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL) // Handle empty list
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // If the node to be deleted is the head node
    if (position == 0)
    {
        // If there's only one node
        if (temp->next == *head)
        {
            free(*head);
            *head = NULL;
            return;
        }

        // Find the last node
        while (temp->next != *head)
        {
            temp = temp->next;
        }

        // Update the last node's next to point to the new head
        temp->next = (*head)->next;
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Traverse to the node just before the position to be deleted
    for (int i = 0; temp != NULL && i < position-1; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == *head)
        {
            printf("Position out of bounds.\n");
            return;
        }
    }

    // If the position is beyond the length of the list
    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        return;
    }

    // Update the previous node's next to bypass the node to be deleted
    prev->next = temp->next;
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

    printf("Original list:\n");
    linkedListTraversal(head);

    // Delete node at position 2 (third node, 55)
    deleteAtPosition(&head, 2);

    printf("List after deleting node at position 2:\n");
    linkedListTraversal(head);

    return 0;
}
