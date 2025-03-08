#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 64  // Fixed block size

int main() {
    int *ptr1 = (int *)malloc(BLOCK_SIZE);  // Allocate 64 bytes
    int *ptr2 = (int *)malloc(BLOCK_SIZE);  // Another 64 bytes


    printf("Allocated two blocks of %d bytes each.\n", BLOCK_SIZE);
    printf("Even if we only need 30 bytes, we waste %d bytes per block.\n", BLOCK_SIZE - 30);

    free(ptr1);
    free(ptr2);
    return 0;
}
