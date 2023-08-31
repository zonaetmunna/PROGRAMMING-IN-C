
#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point p1, p2;

    printf("Enter coordinates for point 1 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter coordinates for point 2 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    printf("Point 1: (%d, %d)\n", p1.x, p1.y);
    printf("Point 2: (%d, %d)\n", p2.x, p2.y);

    return 0;
}
