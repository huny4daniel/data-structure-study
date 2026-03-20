#include <stdio.h>

void change_ptr(int **pp, int *new_addr) {
    *pp = new_addr;
}

int main() {
    int a = 10;
    int b = 20;

    int *p = &a;

    printf("%d\n", *p);

    change_ptr(&p, &b);
    printf("%d\n", *p);

    return 0;
}