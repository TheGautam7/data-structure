#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to traverse and print the linked list
void LinkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to delete nodes at even positions in the linked list
void deleteEvenPositionNodes(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    struct Node *current = head;
    struct Node *temp;

    int position = 1; // Start at position 1 (head is at position 1)

    // Traverse the list, keeping track of odd and even positions
    while (current != NULL && current->next != NULL)
    {
        // Save the node to be deleted
        temp = current->next;

        // Link the current node to the one after the next
        current->next = temp->next;

        // Free the memory of the deleted node
        free(temp);

        // Move to the next odd-positioned node
        current = current->next;
    }
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
    fourth->next = NULL;

    printf("Original Linked List:\n");
    LinkedlistTraversal(head);

    // Call the function to delete nodes at even positions
    deleteEvenPositionNodes(head);

    printf("\nLinked List after deleting even-positioned nodes:\n");
    LinkedlistTraversal(head);

    return 0;
}
