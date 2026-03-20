#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;
    int **pp = &p;

    printf("%d\n", *p);
    printf("%d\n", **pp);
    
    **pp = 99;

    printf("%d\n", a);

    return 0;
}