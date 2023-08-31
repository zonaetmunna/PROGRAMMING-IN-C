// Employee Payroll

#include <stdio.h>

struct Employee {
    char name[50];
    int hoursWorked;
    float hourlyRate;
};

int main() {
    struct Employee emp;

    printf("Enter employee name: ");
    scanf("%s", emp.name);

    printf("Enter hours worked and hourly rate: ");
    scanf("%d %f", &emp.hoursWorked, &emp.hourlyRate);

    float totalSalary = emp.hoursWorked * emp.hourlyRate;
    printf("Employee %s earned %.2f\n", emp.name, totalSalary);

    return 0;
}
