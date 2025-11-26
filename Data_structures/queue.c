#include<stdio.h>
#include<stdlib.h>



typedef struct queue{
    int *arr;
    int currSize;
    int start;
    int end;
    int size;
}Queue;


void initQueue(Queue *q , int size){
        q->size = size;
        q->arr = (int*)malloc(sizeof(int) * q->size);
        q->currSize = 0;
        q->start = -1;
        q->end = -1;
}

int isFull(Queue *q){
    return q->currSize == q->size;
}

int isEmpty(Queue *q){
    return q->currSize == 0;
}


void push(Queue *q , int elem){
    if(isFull(q)){
        printf("queue is full \n");
        return;
    }else if (q->currSize == 0)
    {   
        q->start = 0;
        q->end = 0;
    }else{
        q->end = (q->end + 1 ) % q->size; 
    }

    q->arr[q->end] = elem;

    q->currSize += 1;
}




int pop(Queue *q){

    
    if(isEmpty(q)){
        printf("queue is Empty");
        return 0;
    }

    int elem = q->arr[q->start];
    
    if(q->currSize == 1){
        q->start = -1;
        q->end = -1;
    }else{
       q->start = (q->start + 1) % q->size;
    }

    q->currSize -= 1;

    return elem;
}


int top(Queue *q){
    return q->arr[q->start];
}

int size(Queue *q){
    return q->currSize;
}

int main() {

    Queue q;
    initQueue(&q, 5);

    push(&q, 1);
    push(&q, 2);
    push(&q, 3);

    printf("Popped: %d\n", pop(&q));
    printf("Top: %d\n", top(&q));
}