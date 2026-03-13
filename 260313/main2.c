#include <stdio.h>

int main() {
    int a = 10; // 일반 int 변수
    int *p = &a; // p에 a의 주소 저장

    printf("a의 값: %d\n", a); // 10
    printf("a의 주소: %p\n", &a); // 0x1004
    printf("p의 값: %p\n", p); // 0x1004 (같은)
}