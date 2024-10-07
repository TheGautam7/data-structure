#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elemnets : %d\n", ptr->data);
        ptr = ptr->next;
    }
}


// CASE 3 :  delete at Last Index

struct Node *DeleteLastIndex(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {

        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}



int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = NULL;

    printf("before deletion \n");
    LinkedListTraversal(head);

    
     head = DeleteLastIndex(head);       // for deleting last index
    
    printf("after deletion \n");
    LinkedListTraversal(head);

    return 0;
}