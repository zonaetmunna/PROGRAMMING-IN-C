// Time Conversion
#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

int main() {
    struct Time inputTime;

    printf("Enter time (hours minutes seconds): ");
    scanf("%d %d %d", &inputTime.hours, &inputTime.minutes, &inputTime.seconds);

    int totalSeconds = inputTime.hours * 3600 + inputTime.minutes * 60 + inputTime.seconds;
    printf("Total seconds: %d\n", totalSeconds);

    return 0;
}
