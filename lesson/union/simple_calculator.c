
#include <stdio.h>

union Calculator {
    int operand1;
    int operand2;
    char operator;
};

int main() {
    union Calculator calc;

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &calc.operator);

    printf("Enter operand 1: ");
    scanf("%d", &calc.operand1);

    printf("Enter operand 2: ");
    scanf("%d", &calc.operand2);

    int result;
    switch (calc.operator) {
        case '+':
            result = calc.operand1 + calc.operand2;
            break;
        case '-':
            result = calc.operand1 - calc.operand2;
            break;
        case '*':
            result = calc.operand1 * calc.operand2;
            break;
        case '/':
            result = calc.operand1 / calc.operand2;
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }

    printf("Result: %d\n", result);

    return 0;
}
