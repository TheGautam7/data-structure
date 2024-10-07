#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("stack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack underflow");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;

    }
}

int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i +1;
    if(arrayInd < 0){
        printf("Invalid\n");
    }
    else{
        return sp->arr[arrayInd];
    }
}

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
int stackBottom(struct stack* sp){
    return sp->arr[0];
}
int main(){
    struct stack *sp =(struct stack*)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size* sizeof(struct stack));

    printf("Before pusing empty: %d\n", isEmpty(sp));
    printf("Before pusing Full: %d\n", isFull(sp));

    push(sp, 45);
    push(sp, 56);
    push(sp, 64);
    push(sp, 69);
    push(sp, 26);
    push(sp, 33);
    push(sp, 12);
    push(sp, 82);

    printf("the top most value in stack  is %d\n", stackTop(sp));
    printf("the bottom most value in stack  is %d\n", stackbottom(sp));

    return 0;
}
