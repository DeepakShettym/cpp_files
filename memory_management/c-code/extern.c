#include <stdio.h>

extern int count;  
extern void display();
int main() {
    printf("Count in main: %d\n", count);
    count++;  // Modify the global variable
    display();
    printf("Count after increment: %d\n", count);
    return 0;
}
