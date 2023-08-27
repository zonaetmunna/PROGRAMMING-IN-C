
#include <stdio.h>

// Function declaration with default argument
void greet(char *name, int age = 25) {
    printf("Hello, %s! You are %d years old.\n", name, age);
}

int main() {
    greet("Alice");
    greet("Bob", 30);
    return 0;
}
