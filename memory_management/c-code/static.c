#include<stdio.h>
#include<stdlib.h>

int count2 = 10; // Global variable



int count() {

    static int val = 10;  // Static variable
    val++;  
    count2++; 
    return val;  
}

int main() {
    printf("%d", lol);
    int ans = count();
    printf("%d ", ans);
    printf("%d\n", count2);
    
    ans = count();
    printf("%d ", ans);
    printf("%d\n", count2);
    
    ans = count();
    printf("%d ", ans);
    printf("%d\n", count2);
    
    ans = count();
    printf("%d ", ans);
    printf("%d\n", count2);
    
    printf("%d\n", count2);




 
    
    // printf("%d\n", val);  ERROR: val is a static variable, so it's only accessible inside count()

    return 0;
}
