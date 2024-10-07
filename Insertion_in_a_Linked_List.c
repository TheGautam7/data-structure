#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;

};

void LinkedlistTraversal(struct Node *ptr){
    while(ptr != NULL){
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
    }
}

// insert At Starting 
struct Node* insertAtFirst(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;

}

struct Node* insertAtindex(struct Node* head, int data, int index){
        struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
        struct Node* p = head;
        int i = 0;
        while(i != index-1){
            p = p->next;
            i++;
        }
        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;
        
        return head;
    }

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node)); 

    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 55;
    third->next = fourth;

    fourth->data = 110;
    fourth->next =NULL;

    
    LinkedlistTraversal(head);
    // head = insertAtFirst(head, 56);
    head = insertAtindex(head, 69, 1);
   
    LinkedlistTraversal(head);

    return 0;
}