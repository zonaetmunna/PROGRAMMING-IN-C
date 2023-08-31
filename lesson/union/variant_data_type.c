
#include <stdio.h>
#include <string.h>

union Variant {
    int intValue;
    float floatValue;
    char stringValue[20];
};

int main() {
    union Variant var;
    int choice;

    printf("Select data type (1-Int, 2-Float, 3-String): ");
    scanf("%d", &choice);

    if (choice == 1) {
        var.intValue = 42;
        printf("Int Value: %d\n", var.intValue);
    } else if (choice == 2) {
        var.floatValue = 3.14;
        printf("Float Value: %f\n", var.floatValue);
    } else if (choice == 3) {
        strcpy(var.stringValue, "Hello");
        printf("String Value: %s\n", var.stringValue);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
