#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node * next;
};

// Function to traverse and print the linked list
void LinkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elements : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    
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
    fourth->next = NULL;

    LinkedlistTraversal(head);

    return 0;
}