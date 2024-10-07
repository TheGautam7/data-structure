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
    if (head == NULL)
        return;

    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Function to insert a new node at a given position
struct Node *insertAtPosition(struct Node *head, int position, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 0)
    {
        // Inserting at the head position
        newNode->next = head;

        // Find the last node to update its next pointer
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode; // Update head to point to the new node
    }
    else
    {
        // Insert at position other than the head
        struct Node *current = head;
        int i;
        for (i = 0; i < position - 1; i++)
        {
            if (current->next == head)
            {
                // Position is beyond the end of the list, do nothing
                printf("Position is out of bounds\n");
                free(newNode);
                return head;
            }
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    return head; // Return the possibly updated head
}

// Function to print the linked list
void printList(struct Node *head)
{
    if (head == NULL)
        return;

    struct Node *ptr = head;
    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("(head)\n");
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

    printf("Original List:\n");
    linkedListTraversal(head);

    // Insert a new node with value 45 at position 2
    head = insertAtPosition(head, 2, 45);

    printf("\nList after insertion:\n");
    linkedListTraversal(head);

    return 0;
}
