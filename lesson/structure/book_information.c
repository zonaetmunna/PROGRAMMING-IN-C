
#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    int year;
};

int main() {
    struct Book book1;

    strcpy(book1.title, "The Catcher in the Rye");
    strcpy(book1.author, "J.D. Salinger");
    book1.year = 1951;

    printf("Title: %s\n", book1.title);
    printf("Author: %s\n", book1.author);
    printf("Year: %d\n", book1.year);

    return 0;
}
