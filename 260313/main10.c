#include <stdio.h>

typedef struct {
    char name[50];
    int age;
} Person;

int main() {
    Person alice = {"Alice", 30};
    Person *ptr = &alice;

    printf("Name: %s, Age: %d\n", ptr->name, ptr->age);
    printf("Name: %s, Age: %d\n", alice.name, alice.age);

    ptr->age = 10; // Modifying age through pointer
    printf("Updated Age: %d\n", alice.age);

    return 0;
}