#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node * next;
};

// Function to traverse and print the linked list

void LinkedlistTraversal(struct Node* ptr){
    while(ptr != NULL){
    printf("Element : %d\n", ptr->data);
    ptr = ptr->next;
    }
    
}

struct Node* DeleteAtValue(struct Node* head, int value){
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->data !=value && q->next != NULL ){

        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    return head;
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
    head->data = 4;
    head->next = second;

    // linked second and third nodes
    second->data = 3;
    second->next = third;

    // linked third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // terminate list after fourth node
    fourth->data = 11;
    fourth->next = NULL;
    
     printf("Before Deletion\n");
    LinkedlistTraversal(head);
    
    head = DeleteAtValue(head, 8);
    printf("After Deletion\n");
    LinkedlistTraversal(head);

    return 0;
}