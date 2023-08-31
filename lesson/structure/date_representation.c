
#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int main() {
    struct Date today;

    printf("Enter today's date (day month year): ");
    scanf("%d %d %d", &today.day, &today.month, &today.year);

    printf("Date: %02d/%02d/%04d\n", today.month, today.day, today.year);

    return 0;
}
