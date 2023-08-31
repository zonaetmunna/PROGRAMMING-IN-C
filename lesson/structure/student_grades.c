// Student Grades
#include <stdio.h>

struct Student {
    char name[50];
    float grades[5];
};

int main() {
    struct Student student1;

    printf("Enter student name: ");
    scanf("%s", student1.name);

    printf("Enter 5 grades: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &student1.grades[i]);
    }

    float average = 0.0;
    for (int i = 0; i < 5; i++) {
        average += student1.grades[i];
    }
    average /= 5.0;

    printf("Student: %s\n", student1.name);
    printf("Average grade: %.2f\n", average);

    return 0;
}
