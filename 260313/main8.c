#include <stdio.h>

void min_max(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int arr[] = {3, 1, 9, 5, 2};
    int lo, hi;

    min_max(arr, sizeof(arr) / sizeof(arr[0]), &lo, &hi);
    printf("Min: %d, Max: %d\n", lo, hi);

    return 0;
}