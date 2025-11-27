#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node* next; 
}Node;


typedef struct {
    Node* start;
    Node* end;
    int size;
}Queue;


void initQueue(Queue *q){
    q->start = NULL;
    q->end = NULL;
    q->size = 0;
}

int isEmpty(Queue *q){
    return (q->start == NULL);
}

int top(Queue *q){
    if(isEmpty(q)){
        printf("queue is Empty");
        return -1;
    }

    return q->start->data;
}

int size(Queue *q){
    return q->size;
}


void push(Queue *q, int elem){
  
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->next = NULL;
    newNode->data = elem;
    if(q->start == NULL){
        q->start = newNode;
        q->end = newNode;
    }else{
        q->end->next = newNode;
        q->end = newNode;
    }

    q->size += 1;
}


int pop(Queue *q){
    if(isEmpty(q)){
        printf("queue is empty\n");
        return -1;
    }

    Node* temp = q->start;
    int elem = q->start->data;

    if(q->start->next == NULL){
        q->start = NULL;
        q->end = NULL;
    }else{
        q->start = q->start->next;
    }

    q->size -= 1;
    free(temp);

    return elem;

    
}


int main(){

    Queue q ;
    initQueue(&q);
    push(&q , 4);
    push(&q , 3);
    push(&q , 2);
    push(&q , 1);


    int  poped1 = pop(&q);
    int s1 = size(&q);
    printf("poped1 : %d \n" , poped1);
    printf("size : %d \n ", s1);

    int  poped2 = pop(&q);
    int s2 = size(&q);
    printf("poped2 : %d \n" , poped2);
    printf("size : %d \n ", s2);
  
    int  poped3 = pop(&q);
    int  poped4 = pop(&q);

    
    printf("poped3 : %d \n" , poped3);
    printf("poped4 : %d \n" , poped4);

    int poped5 = pop(&q);
    printf("poped5 : %d \n" , poped5);

    int s3 = size(&q);

    printf("size : %d \n ", s3);

    
    return 0;
}