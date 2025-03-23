#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    ptr = (int *)calloc(5, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }   

   
    for (int i = 0; i < 5; i++) {
        printf("%d\n", *ptr);
        ptr = ptr + 1;  
    } 

    /*output :
    0
    0
    0
    0
    0
    */

    free(ptr);  

    return 0;
}
