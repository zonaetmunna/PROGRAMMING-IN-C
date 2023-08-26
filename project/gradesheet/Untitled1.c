
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for marks distribution
#define THEORY_TOTAL_MARKS 100
#define LAB_TOTAL_MARKS 100

// Structure to store student information
struct Student {
    int studentID;
    char studentName[50];
};

// Structure to store course information
struct Course {
    char courseCode[10];
    char courseTitle[50];
    int credit;
    char courseType[5];
};

// Structure to store course results
struct Results {
    float ksa1;
    float ksa2;
    float classTest;
    float midterm;
    float finalExam;
    float labReport;
    float labPerformance;
    float projectViva;
    float labFinalExam;
};

// Function to calculate total marks
float calculateTotalMarks(struct Results results, struct Course course) {
    if (strcmp(course.courseType, "theory") == 0) {
        return results.ksa1 + results.ksa2 + results.classTest + results.midterm + results.finalExam;
    } else if (strcmp(course.courseType, "lab") == 0) {
        return results.labReport + results.labPerformance + results.projectViva + results.labFinalExam;
    } else {
        printf("Invalid course type!\n");
        exit(1);
    }
}

// Function to calculate grade point
float calculateGradePoint(float totalMarks, struct Course course) {
    if (strcmp(course.courseType, "theory") == 0) {
        return (totalMarks / THEORY_TOTAL_MARKS) * 4.0;
    } else if (strcmp(course.courseType, "lab") == 0) {
        return (totalMarks / LAB_TOTAL_MARKS) * 4.0;
    } else {
        printf("Invalid course type!\n");
        exit(1);
    }
}

// Function to calculate letter grade
char calculateLetterGrade(float gradePoint) {
    if (gradePoint >= 4.0) {
        return 'A';
    } else if (gradePoint >= 3.7) {
        return 'A-';
    } else if (gradePoint >= 3.3) {
        return 'B+';
    } else if (gradePoint >= 3.0) {
        return 'B';
    } else if (gradePoint >= 2.7) {
        return 'B-';
    } else if (gradePoint >= 2.3) {
        return 'C+';
    } else if (gradePoint >= 2.0) {
        return 'C';
    } else if (gradePoint >= 1.7) {
        return 'D';
    } else {
        return 'F';
    }
}

// Function to search for student results by student ID
void searchResults(struct Student students[], struct Results results[], struct Course course, int numStudents, int searchID) {
    int i, found = 0;

    for (i = 0; i < numStudents; i++) {
        if (students[i].studentID == searchID) {
            printf("\nStudent ID: %d\n", students[i].studentID);
            printf("Student Name: %s\n", students[i].studentName);
            printf("Total Marks: %.2f\n", calculateTotalMarks(results[i], course));
            printf("Grade Point: %.2f\n", calculateGradePoint(calculateTotalMarks(results[i], course), course));
            printf("Letter Grade: %c\n", calculateLetterGrade(calculateGradePoint(calculateTotalMarks(results[i], course), course)));
                       found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student ID not found!\n");
    }
}

// Function to swap two elements
void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort based on course results
void sortByResults(struct Student students[], struct Results results[], struct Course course, int numStudents) {
    int i, j;

    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            float totalMarks1 = calculateTotalMarks(results[j], course);
            float totalMarks2 = calculateTotalMarks(results[j + 1], course);

            if (totalMarks1 < totalMarks2) {
                swap(&students[j], &students[j + 1]);
                swap(&results[j], &results[j + 1]);
            }
        }
    }
}

// Function to perform bubble sort based on student ID
void sortByID(struct Student students[], struct Results results[], int numStudents) {
    int i, j;

    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            if (students[j].studentID > students[j + 1].studentID) {
                swap(&students[j], &students[j + 1]);
                swap(&results[j], &results[j + 1]);
            }
        }
    }
}

// Function to generate result summary graph
void generateGraph(struct Student students[], struct Results results[], struct Course course, int numStudents) {
    int i, j;
    int gradesCount[9] = { 0 }; // Array to store the count of each grade
    char grades[9][3] = { "A+", "A ", "A-", "B+", "B ", "B-", "C+", "C ", "D " };

    for (i = 0; i < numStudents; i++) {
        float gradePoint = calculateGradePoint(calculateTotalMarks(results[i], course), course);

        if (gradePoint >= 4.0) {
            gradesCount[0]++;
        } else if (gradePoint >= 3.7) {
            gradesCount[1]++;
        } else if (gradePoint >= 3.3) {
            gradesCount[2]++;
        } else if (gradePoint >= 3.0) {
            gradesCount[3]++;
        } else if (gradePoint >= 2.7) {
            gradesCount[4]++;
        } else if (gradePoint >= 2.3) {
            gradesCount[5]++;
        } else if (gradePoint >= 2.0) {
            gradesCount[6]++;
        } else if (gradePoint >= 1.7) {
            gradesCount[7]++;
        } else {
            gradesCount[8]++;
        }
    }

    printf("\nResult Summary:\n");
    for (i = 0; i < 9; i++) {
        printf("%s %d ", grades[i], gradesCount[i]);
        for (j = 0; j < gradesCount[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int numStudents, i;
    int searchID;
    struct Course course;
    struct Student* students;
     struct Results* results;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    students = (struct Student*)malloc(numStudents * sizeof(struct Student));
    results = (struct Results*)malloc(numStudents * sizeof(struct Results));

    printf("\nEnter Course Information:\n");
    printf("Course Code: ");
    scanf("%s", course.courseCode);
    printf("Course Title: ");
    scanf(" %[^\n]s", course.courseTitle);
    printf("Credit: ");
    scanf("%d", &course.credit);
    printf("Course Type (theory or lab): ");
    scanf("%s", course.courseType);

    printf("\nEnter Student Information and Results:\n");
    for (i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Student ID: ");
        scanf("%d", &students[i].studentID);
        printf("Student Name: ");
        scanf(" %[^\n]s", students[i].studentName);

        printf("Results:\n");
        if (strcmp(course.courseType, "theory") == 0) {
            printf("KSA1 (10 marks): ");
            scanf("%f", &results[i].ksa1);
            printf("KSA2 (10 marks): ");
            scanf("%f", &results[i].ksa2);
            printf("Class Test (10 marks, average of 2 class tests): ");
            scanf("%f", &results[i].classTest);
            printf("Midterm (30 marks): ");
            scanf("%f", &results[i].midterm);
            printf("Final Exam (40 marks): ");
            scanf("%f", &results[i].finalExam);
        } else if (strcmp(course.courseType, "lab") == 0) {
            printf("Lab Report (15 marks): ");
            scanf("%f", &results[i].labReport);
            printf("Continuous Lab Performance (25 marks): ");
            scanf("%f", &results[i].labPerformance);
            printf("Project and Viva (30 marks): ");
            scanf("%f", &results[i].projectViva);
            printf("Lab Final Exam (30 marks): ");
            scanf("%f", &results[i].labFinalExam);
        } else {
            printf("Invalid course type!\n");
            exit(1);
        }
    }

    // Calculate and display grade sheet for each student
    for (i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Student ID: %d\n", students[i].studentID);
        printf("Student Name: %s\n", students[i].studentName);
        printf("Total Marks: %.2f\n", calculateTotalMarks(results[i], course));
        printf("Grade Point: %.2f\n", calculateGradePoint(calculateTotalMarks(results[i], course), course));
        printf("Letter Grade: %c\n", calculateLetterGrade(calculateGradePoint(calculateTotalMarks(results[i], course), course)));
    }

    // Search for student results by ID
    printf("\nEnter student ID to search for results: ");
    scanf("%d", &searchID);
    searchResults(students, results, course, numStudents, searchID);

    // Sort students based on results
    sortByResults(students, results, course, numStudents);

    printf("\nSorted by Results:\n");
    for (i = 0; i < numStudents; i++) {
            printf("Student ID: %d\n", students[i].studentID);
        printf("Student Name: %s\n", students[i].studentName);
        printf("Total Marks: %.2f\n", calculateTotalMarks(results[i], course));
        printf("Grade Point: %.2f\n", calculateGradePoint(calculateTotalMarks(results[i], course), course));
        printf("Letter Grade: %c\n", calculateLetterGrade(calculateGradePoint(calculateTotalMarks(results[i], course), course)));
    }
     // Sort students based on student ID
    sortByID(students, results, numStudents);

    printf("\nSorted by Student ID:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Student ID: %d\n", students[i].studentID);
        printf("Student Name: %s\n", students[i].studentName);
        printf("Total Marks: %.2f\n", calculateTotalMarks(results[i], course));
        printf("Grade Point: %.2f\n", calculateGradePoint(calculateTotalMarks(results[i], course), course));
        printf("Letter Grade: %c\n", calculateLetterGrade(calculateGradePoint(calculateTotalMarks(results[i], course), course)));
    }

    // Generate result summary graph
    generateGraph(students, results, course, numStudents);

    // Free dynamically allocated memory
    free(students);
    free(results);

    return 0;
}

