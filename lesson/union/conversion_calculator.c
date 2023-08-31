#include <stdio.h>

union Measurement {
    float meters;
    float feet;
};

int main() {
    union Measurement length;
    int choice;

    printf("Select unit (1-Meters, 2-Feet): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter length in meters: ");
        scanf("%f", &length.meters);
        length.feet = length.meters * 3.281;
        printf("Length in feet: %.2f\n", length.feet);
    } else if (choice == 2) {
        printf("Enter length in feet: ");
        scanf("%f", &length.feet);
        length.meters = length.feet / 3.281;
        printf("Length in meters: %.2f\n", length.meters);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

