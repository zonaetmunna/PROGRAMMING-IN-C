
#include <stdio.h>

// Function declaration
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    printf("Before swapping: x = %d, y = %d\n", x, y);

    // Call the swap function
    swap(&x, &y);

    printf("After swapping: x = %d, y = %d\n", x, y);
    return 0;
}
