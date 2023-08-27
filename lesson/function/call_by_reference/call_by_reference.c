
#include <stdio.h>

void modifyValue(int *ptr) {
    *ptr = *ptr * 2;
    printf("Inside function: %d\n", *ptr);
}

int main() {
    int num = 10;
    modifyValue(&num);
    printf("Outside function: %d\n", num);
    return 0;
}
