// Car Information

#include <stdio.h>
#include <string.h>

struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
};

int main() {
    struct Car car1;

    strcpy(car1.make, "Toyota");
    strcpy(car1.model, "Corolla");
    car1.year = 2022;
    car1.price = 20000.0;

    printf("Car Details:\n");
    printf("Make: %s\n", car1.make);
    printf("Model: %s\n", car1.model);
    printf("Year: %d\n", car1.year);
    printf("Price: %.2f\n", car1.price);

    return 0;
}
