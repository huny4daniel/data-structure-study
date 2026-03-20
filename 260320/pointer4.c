#include <stdio.h>   // printf, scanf 등 표준 입출력 함수 포함
#include <string.h>  // 문자열 처리 함수 포함 (이 코드에서는 미사용)
#include <stdlib.h>  // malloc, free 등 동적 메모리 함수 포함

int main() {
    int n;  // 배열 크기를 저장할 변수 선언 (스택 메모리에 할당)

    printf("배열의 크기 입력: ");  // 사용자에게 입력 안내 출력
    scanf("%d", &n);               // 정수를 입력받아 n에 저장 (&n = n의 주소)

    // malloc: heap 메모리에서 n개의 int 크기만큼 동적 할당
    // sizeof(int) = 4바이트, 총 n*4바이트 확보
    // (int *) 캐스팅: malloc의 반환 타입 void*를 int*로 변환
    int *arr = (int *) malloc(n * sizeof(int));

    // 동적 할당 실패 시 malloc은 NULL을 반환
    // 메모리가 부족하거나 요청 크기가 너무 클 때 발생
    if (arr == NULL) {
        printf("메모리 부족\n");
        
        return 1;  // 비정상 종료 (0이 아닌 값 = 오류)
    }

    // 배열 초기화: arr[0]=0, arr[1]=10, arr[2]=20, ...
    // arr[i]는 *(arr + i)와 동일 (포인터 산술)
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;  // heap에 할당된 메모리에 값 저장
    }

    // 배열 출력: 포인터 arr을 배열처럼 인덱스로 접근
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);   // heap에 할당한 메모리 반환 (메모리 누수 방지)
    arr = NULL;  // 해제된 주소를 가리키는 dangling pointer 방지

    return 0;  // 정상 종료
}
