
#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

int main() {
    struct Employee employees[3];

    for (int i = 0; i < 3; i++) {
        printf("Enter name, ID, and salary for employee %d: ", i + 1);
        scanf("%s %d %f", employees[i].name, &employees[i].id, &employees[i].salary);
    }

    printf("\nEmployee Records:\n");
    for (int i = 0; i < 3; i++) {
        printf("Employee %d: Name: %s, ID: %d, Salary: %.2f\n", i + 1, employees[i].name, employees[i].id, employees[i].salary);
    }

    return 0;
}
