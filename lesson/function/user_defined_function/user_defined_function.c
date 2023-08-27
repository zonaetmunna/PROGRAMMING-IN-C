#include <stdio.h>

// Function to calculate the sum of two integers
int sum(int a, int b) {
    return a + b;
}

int main() {
    int x = 5, y = 7;
    int result = sum(x, y); // Calling the user-defined function
    printf("Sum: %d\n", result);
    return 0;
}

