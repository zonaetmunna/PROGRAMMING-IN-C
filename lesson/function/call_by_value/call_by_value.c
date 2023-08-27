
#include <stdio.h>

void modifyValue(int x) {
    x = x * 2;
    printf("Inside function: %d\n", x);
}

int main() {
    int num = 10;
    modifyValue(num);
    printf("Outside function: %d\n", num);
    return 0;
}
