#include <stdio.h>

union Employee {
    int empID;
    float salary;
};

int main() {
    union Employee employees[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter employee ID for employee %d: ", i + 1);
        scanf("%d", &employees[i].empID);
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &employees[i].salary);
    }

    printf("\nEmployee Records:\n");
    for (int i = 0; i < 5; i++) {
        printf("Employee %d - ID: %d, Salary: %.2f\n", i + 1, employees[i].empID, employees[i].salary);
    }

    return 0;
}

