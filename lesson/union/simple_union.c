
#include <stdio.h>

union Number {
    int intValue;
    float floatValue;
    char charValue;
};

int main() {
    union Number num;
    num.intValue = 42;
    printf("Int Value: %d\n", num.intValue);

    num.floatValue = 3.14;
    printf("Float Value: %f\n", num.floatValue);

    num.charValue = 'A';
    printf("Char Value: %c\n", num.charValue);

    return 0;
}
