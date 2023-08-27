
#include <stdio.h>

// Function declaration
int square(int num) {
    return num * num;
}

int main() {
    int num = 4;
    int result = square(num);
    printf("Square of %d: %d\n", num, result);
    return 0;
}
