
#include <stdio.h>

union Date {
    struct {
        int day;
        int month;
        int year;
    } dateParts;
    char formatted[20];
};

int main() {
    union Date date;

    printf("Enter day, month, and year: ");
    scanf("%d %d %d", &date.dateParts.day, &date.dateParts.month, &date.dateParts.year);

    sprintf(date.formatted, "%02d/%02d/%04d", date.dateParts.month, date.dateParts.day, date.dateParts.year);
    printf("Formatted date (MM/DD/YYYY): %s\n", date.formatted);

    return 0;
}
