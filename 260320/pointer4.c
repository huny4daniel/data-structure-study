#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;

    printf("배열의 크기 입력: ");
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("메모리 부족\n");
        
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}
