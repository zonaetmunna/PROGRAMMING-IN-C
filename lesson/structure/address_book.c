// Address Book

#include <stdio.h>
#include <string.h>

struct Address {
    char street[100];
    char city[50];
    char state[50];
    int zipCode;
};

struct Contact {
    char name[50];
    struct Address address;
};

int main() {
    struct Contact person;

    printf("Enter contact name: ");
    scanf("%s", person.name);

    printf("Enter address (street city state zip): ");
    scanf("%s %s %s %d", person.address.street, person.address.city, person.address.state, &person.address.zipCode);

    printf("Contact Details:\n");
    printf("Name: %s\n", person.name);
    printf("Address: %s, %s, %s, %d\n", person.address.street, person.address.city, person.address.state, person.address.zipCode);

    return 0;
}
