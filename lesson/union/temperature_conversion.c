
#include <stdio.h>

union Temperature {
    float celsius;
    float fahrenheit;
};

int main() {
    union Temperature temp;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &temp.celsius);

    temp.fahrenheit = (temp.celsius * 9 / 5) + 32;
    printf("Temperature in Fahrenheit: %.2f\n", temp.fahrenheit);

    return 0;
}
