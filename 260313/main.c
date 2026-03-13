#include <stdio.h>

int main() {
    int a = 10;

    printf("address of a: 0x%p\n", &a); // 0x: 16진수 표시, %p는 포인터 출력
    printf("Value of a: %d\n", a); // %d는 int 출력

    return 0;
}