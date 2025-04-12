#include <stdio.h>
#include <stddef.h>  // for size_t

struct some_data {
    int a;
    int b;
    char c;
};

// Function to get the struct base address from pointer to member `c`
void getContainer(char *ptr) {
    // Calculate offset of `c` from start of struct
    size_t offset = (size_t)((char*)&(((struct some_data*)0)->c));

    // Subtract offset from member pointer to get struct base
    struct some_data *data = (struct some_data*)(ptr - offset);

    // Print recovered values
    printf("a = %d\n", data->a);
    printf("b = %d\n", data->b);
    printf("c = %c\n", data->c);
}

int main() {
    struct some_data data1;

    data1.a = 10;
    data1.b = 20;
    data1.c = 'a';

    // Always pass pointer to member `c`
    getContainer(&data1.c);

    return 0;
}
