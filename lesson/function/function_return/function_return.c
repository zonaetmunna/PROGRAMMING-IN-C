
#include <stdio.h>

// Function declaration
int add(int a, int b);

int main() {
    int num1 = 5, num2 = 10;
    int sum = add(num1, num2); // Call the function and store its return value in the variable "sum"
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    return 0;
}

// Function definition
int add(int a, int b) {
    int result = a + b;
    return result;
}
