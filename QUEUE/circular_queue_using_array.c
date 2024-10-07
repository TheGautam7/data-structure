#include<stdio.h>
#include<stdlib.h>

struct circularqueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularqueue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0; 
}

int isFull(struct circularqueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct circularqueue *q, int val){
    if(isFull(q)){
        printf("Queue is full. \n");
    }
    else{
         q->r =(q->r+1)%q->size;
         q->arr[q->r] = val;
         printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct circularqueue *q){
    int a =-1;
    if(isEmpty(q)){
        printf("This Queue is empty");
    }
    else{
        q->f =(q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}


int main(){
    struct circularqueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    enqueue(&q, 45);
    enqueue(&q, 46);
    enqueue(&q, 47);
    enqueue(&q, 48);

    printf("dequeue elements : %d \n", dequeue(&q));
    printf("dequeue elements : %d \n", dequeue(&q));
    printf("dequeue elements : %d \n", dequeue(&q));
    enqueue(&q, 49);
    enqueue(&q, 50);


    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
 

    return 0;
}