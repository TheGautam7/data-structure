// C Program to create a Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int data;

    struct Node *next;

    struct Node *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

int main()
{

    Node *head = createNode(10);
    Node *second = createNode(20);
    Node *third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Doubly Linked List: ");
    Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}