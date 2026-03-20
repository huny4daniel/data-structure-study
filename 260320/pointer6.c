#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp_asc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int cmp_des(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int main() {
    int arr[] = {100, 20, 1, 200, 120};

    int (*cmp_desc)(const void *, const void *) = cmp_asc;

    qsort(arr, 5, sizeof(int), cmp_desc);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    cmp_desc = cmp_des;

    qsort(arr, 5, sizeof(int), cmp_desc);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}