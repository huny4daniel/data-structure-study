#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr; // 배열의 첫 번째 요소를 가리키는 포인터

    printf("%d\n", *ptr); // 10 출력
    printf("%d\n", *(ptr + 1)); // 20 출력
    printf("%d\n", *(ptr + 2)); // 30 출력

    return 0;
}