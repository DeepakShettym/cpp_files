#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, *start;

    ptr = (int *)malloc(5 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    start = ptr;  

   
    for (int i = 0; i < 5; i++) {
        *ptr = i;
        ptr = ptr + 1;
    }

    ptr = start;  

   
    for (int i = 0; i < 5; i++) {
        printf("%d\n", *ptr);
        ptr = ptr + 1;  
    }

    free(start);  

    return 0;
  }