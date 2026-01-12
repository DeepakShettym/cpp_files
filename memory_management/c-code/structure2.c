#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int a;
    char *b;
} childStruct;

typedef struct {
    int c;
    childStruct *ch;
} myStruct;


myStruct* createmyStruct(int c , childStruct *ch){
    myStruct *obj = malloc(sizeof(myStruct));
    if(!obj) return NULL;
    obj->c = c;
    obj->ch = ch;
    return obj;   
}

void distroyMystruct(myStruct *mys){
    if(!mys) return;
     free(mys);
}

childStruct* createChild(const char *s , int a){
    childStruct* ch = malloc(sizeof(childStruct));
    if(!ch) return NULL;
    ch->b = malloc(strlen(s) + 1);
    if(!ch->b) return NULL;
    ch->a = a;
    strcpy(ch->b , s);
    return ch;
}

void distroyChild(childStruct *ch){
    if(!ch) return;
    free(ch->b);
    free(ch);
}



int main() {

    char arr[7] = "deepak";
    

    childStruct* child = createChild(arr , 10);
    myStruct* my = createmyStruct(20 , child);

    
    printf("%s" , my->ch->b);
    

    printf(" c = %d , a = %d \n",my->c , my->ch->a);


    
    
    myStruct* my1 = createmyStruct(100 , child);
   

    
    printf("%s" , my->ch->b);
    

    printf(" c = %d , a = %d \n",my->c , my->ch->a);

    childStruct *newchild = malloc(sizeof(childStruct));

    newchild->b = malloc(strlen(child) + 1);

    myStruct *newmy = malloc(sizeof(myStruct));
    newmy->ch = newchild;

    //
    memcpy(newchild , child, sizeof(child));
    memcpy(newchild->b, child->b, strlen(child->b) + 1);
    printf("bro num = %d \n", newchild->a);

    printf("bro = %s \n" , newmy->ch->b);

    distroyChild(child);
    distroyMystruct(my);
    distroyMystruct(my1);
    free(newchild);
    free(newmy);

    // printf(" c = %d , a = %d ",my->c , my->ch->a); don't do this (seg fault)
    


    return 0;
}
