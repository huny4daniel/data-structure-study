#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]); // 배열의 요소 개수 계산

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]); // 배열 요소 출력
    }
    printf("\n");
    
    int *ptr = arr; // 배열의 첫 번째 요소를 가리키는 포인터

    for (int i = 0; i < n; i++) {
        printf("%d ", *ptr); // 포인터를 이용해 배열 요소 출력
        ptr++; // 포인터를 다음 요소로 이동
    }

    return 0;
}