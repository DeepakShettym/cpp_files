#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr1 = malloc(100);
    void *ptr2 = malloc(200);
    void *ptr3 = malloc(300);

    free(ptr2);  // Free 200 bytes
    void *ptr4 = malloc(250);  // Needs 250 bytes but can't fit in the freed 200-byte block

    if (ptr4 == NULL)
        printf("Memory allocation failed due to external fragmentation!\n");
    else
        printf("Memory allocated successfully.\n");

    free(ptr1);
    free(ptr3);
    free(ptr4);
    return 0;
}
