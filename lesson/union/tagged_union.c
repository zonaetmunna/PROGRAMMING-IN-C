#include <stdio.h>
#include <math.h>

union Shape {
    struct Rectangle {
        float width;
        float height;
    } rect;
    struct Circle {
        float radius;
    } circle;
    struct Triangle {
        float base;
        float height;
    } triangle;
};

int main() {
    union Shape shape;
    int choice;

    printf("Select shape (1-Rectangle, 2-Circle, 3-Triangle): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter width and height of rectangle: ");
        scanf("%f %f", &shape.rect.width, &shape.rect.height);
        printf("Area of rectangle: %.2f\n", shape.rect.width * shape.rect.height);
    } else if (choice == 2) {
        printf("Enter radius of circle: ");
        scanf("%f", &shape.circle.radius);
        printf("Area of circle: %.2f\n", M_PI * shape.circle.radius * shape.circle.radius);
    } else if (choice == 3) {
        printf("Enter base and height of triangle: ");
        scanf("%f %f", &shape.triangle.base, &shape.triangle.height);
        printf("Area of triangle: %.2f\n", 0.5 * shape.triangle.base * shape.triangle.height);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

