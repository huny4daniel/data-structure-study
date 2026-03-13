#include <stdio.h>

void add_one(int a) {
    a = a + 1;
}

int main() {
    int a = 10;

    add_one(a);
    printf("Value of a after add_one: %d\n", a);

    return 0;
}