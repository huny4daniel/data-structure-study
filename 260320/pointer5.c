#include <stdio.h>
#include <string.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int main() {
    int (*fp)(int, int) = add;
    printf("%d\n", fp(3, 4));

    fp = sub;
    printf("%d\n", fp(10, 4));

    return 0;
}