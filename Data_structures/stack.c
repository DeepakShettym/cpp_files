#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
  
} Stack;

void initStack(Stack *s){
    s->top = -1;
   
}

int isFull(Stack *s){
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

void push(Stack *s, int elem){
    if(isFull(s)){
        printf("Stack is full\n");
        return;
    }
    s->arr[++(s->top)] = elem;
    
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
   
    return s->arr[(s->top)--];
}

int topElement(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

int size(Stack *s){
    return (s->top) ;
}

int main(){
    Stack *s = (Stack*)malloc(sizeof(Stack)); 

    initStack(s);

    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);

    printf("Top element = %d\n", topElement(s));

    pop(s);

    printf("Top element = %d\n", topElement(s));
    printf("size = %d\n", size(s));


    return 0;
}
