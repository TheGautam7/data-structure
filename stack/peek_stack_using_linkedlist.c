#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* top = NULL;
// Function to traverse and print the linked list
void LinkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elements : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(struct Node* top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }

}
int isfull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }
    else{
        return 0;
        }
}
// push in stack using linked list.
struct Node* push(struct Node* top, int x){
    if(isfull(top)){
        printf("stack overflow");
    }
    else{
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

// pop in stack using linked list.
int pop(struct Node* tp){
    if(isEmpty(tp)){
        printf("stack underflow\n");
    }
    else{
        struct Node* n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos){
    struct Node* ptr = top;
    for(int i = 0;(i < pos-1 && pos != NULL); i++){
        ptr = ptr->next;
    }
    if(ptr != NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
    
}
int main(){
    
    top = push(top, 69);
    top = push(top, 70);
    top = push(top, 71);
    top = push(top, 72);
    
    LinkedlistTraversal(top);
    for (int i = 1; i < 5; i++)
    {
        printf("value at position %d is : %d\n",i, peek(i));
    }
    

    return 0;
}