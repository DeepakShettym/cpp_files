#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int i;

    
    ptr = (int *)malloc(3 * sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i < 3; i++) {
        ptr[i] = i + 1; 
    }

    printf("Before realloc:\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    
    ptr = (int *)realloc(ptr, 5 * sizeof(int));

    if (ptr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

  
    for (i = 3; i < 5; i++) {
        ptr[i] = i + 1;  // 4, 5
    }

   
    printf("After realloc:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr); 

    return 0;
}
