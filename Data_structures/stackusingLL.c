#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int data;
    struct Node* next;

}Node;



typedef struct 
{
    Node* top;
    int size;
}Stack;


void initStack(Stack *s){
  
    s->top = NULL;
    s->size = 0;
}

int isEmpty(Stack *s){
    return (s->top == NULL);
}

void push(Stack *s , int elem){
        Node* newNode = malloc(sizeof(Node));
        if (!newNode) {
        printf("Memory allocation failed\n");
        return;  
        }
        newNode->data = elem;
        newNode->next = NULL;

    
        newNode->next = s->top;
        s->top = newNode;
        

        s->size += 1;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("stack is empty \n");
        return -1;
    }

    int elem = s->top->data;

  
    Node* freenode = s->top;
    s->top = s->top->next;
    free(freenode);

    s->size -= 1;

    return elem;
}

int size(Stack *s){
    return s->size;
}


int top(Stack *s){
    if (isEmpty(s)) {
    printf("stack is empty\n");
    return -1; 
}

return s->top->data;

}


int main()
{

    Stack *s =  malloc (sizeof(Stack));
    initStack(s);
    push(s,1);
    push(s,2);
    push(s,3);
    int poped = pop(s);

    printf("poped : %d \n", poped);
    int toped = top(s);
    
    printf("toped : %d \n", toped);
   


    int poped1 =  pop(s);
    printf("poped1 : %d \n", poped1);
    int poped2 =  pop(s);
    printf("poped2 : %d \n", poped2);
    int poped3 = pop(s);
    printf("poped3 : %d \n", poped3);

    int empty = isEmpty(s);

    printf("isEmpty %d \n " , empty);

    free(s);

    return 0;

    
}







