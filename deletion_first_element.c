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

// CASE 1 : DeleteFirst

struct Node *DeleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// CASE 2 :  delete at any index

struct Node *DeleteAtIndex(struct Node *head, int index)
{

    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i != index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
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

// CASE 4 : Deleting  the Element with a given Value

struct Node *DeleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {

        p = p->next;
        q = q->next;
    }
    p->next = q->next;
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

    head = DeleteFirst(head); // for deleting first element in the linked list
    // head = DeleteAtIndex(head, 2);  // for deleting at given index
    // head = DeleteLastIndex(head);       // for deleting last index
    // head = DeleteAtValue(head, 3);
    printf("after deletion \n");
    LinkedListTraversal(head);

    return 0;
}