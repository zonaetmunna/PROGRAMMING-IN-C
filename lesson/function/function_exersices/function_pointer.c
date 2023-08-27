
#include <stdio.h>

// Function declaration
int add(int a, int b) {
    return a + b;
}

int main() {
    // Declare a function pointer
    int (*ptr)(int, int) = add;

    int result = ptr(3, 4);
    printf("Result: %d\n", result);
    return 0;
}
