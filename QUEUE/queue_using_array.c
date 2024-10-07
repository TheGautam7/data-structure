#include<stdio.h>
#include<stdlib.h>
    struct queue{
        int size;
        int f;
        int r;
        int *arr;
    };

int isFull(struct queue *q){
    if(q->r == q->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue *q){
    if(q->r == q->f){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
    }
    else{
        q->r = q->r+1;
        q->arr[q->r] = val;
        printf("Enqueued: %d\n", val);  // Print the enqueued element
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 8;
    q.f = -1;
    q.r = -1;
    q.arr = (int*)malloc(q.size * sizeof(int)); 

    enqueue(&q, 45);
    enqueue(&q, 46);
    enqueue(&q, 47);
    enqueue(&q, 47);
    
    printf("Dequeue Elemnts \n");
    printf("Dequeued: %d\n", dequeue(&q));  
    printf("Dequeued: %d\n", dequeue(&q));  
    printf("Dequeued: %d\n", dequeue(&q));  
    printf("Dequeued: %d\n", dequeue(&q));  

    // Free allocated memory
    // free(q.arr);

    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
    
    return 0;
}