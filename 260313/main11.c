#include <stdio.h>

typedef struct {
    char name[50];
    int age;
    double gpa;
} Person;

int main() {
    Person students[] = {
        {"Alice", 20, 3.5},
        {"Bob", 22, 3.8},
        {"Charlie", 19, 3.2}
    };

    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d, GPA: %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }

    Person *ptr = students; // Pointing to the first element of the array

    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d, GPA: %.2f\n", ptr->name, ptr->age, ptr->gpa);
        ptr++; // Move to the next element in the array
    }

    return 0;
}