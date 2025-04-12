#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // Step 1: calculate byte difference between two addresses
    int diff = (char*)&arr[4] - (char*)&arr[0];  // = +16

    // Step 2: move back in memory by `diff` bytes
    int *ptr = (int *)((char*)&arr[4] - diff);

    printf("addr arr[0] = %p\n", (void*)&arr[0]);
    printf("addr from ptr = %p\n", (void*)ptr);
    printf("ptr points to value = %d\n", *ptr);  // should be 10

    return 0;
}
