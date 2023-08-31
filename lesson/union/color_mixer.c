
#include <stdio.h>

union Color {
    struct {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    } rgb;
    unsigned int hex;
};

int main() {
    union Color color1, color2, mixedColor;

    printf("Enter RGB values for color 1 (R G B): ");
    scanf("%hhu %hhu %hhu", &color1.rgb.red, &color1.rgb.green, &color1.rgb.blue);

    printf("Enter RGB values for color 2 (R G B): ");
    scanf("%hhu %hhu %hhu", &color2.rgb.red, &color2.rgb.green, &color2.rgb.blue);

    mixedColor.rgb.red = (color1.rgb.red + color2.rgb.red) / 2;
    mixedColor.rgb.green = (color1.rgb.green + color2.rgb.green) / 2;
    mixedColor.rgb.blue = (color1.rgb.blue + color2.rgb.blue) / 2;

    printf("Mixed Color - R: %hhu, G: %hhu, B: %hhu\n", mixedColor.rgb.red, mixedColor.rgb.green, mixedColor.rgb.blue);

    return 0;
}
