#include <stdio.h>

void reset_variable(int x) {
    x = 0;
}

void reset_variable_reference(int *x) {
    *x = 0;
}

void reset_array(int a[], int len) {
    for (int i = 0; i < len; i++) {
        a[i] = 0;
    }
}

int main() {
    int A[3] = {10, 20, 30}, x = 2024;

    reset_variable(x);
    reset_array(A, 3);

    printf("변수 초기화 (call by value) x = %d \n", x);

    reset_variable_reference(&x);
    printf("변수 초기화 (call by reference) x = %d \n", x);

    printf("배열 초기화 : ");

    for (int i = 0; i < 3; i++) {
        printf("A[%d] = %d ", i, A[i]);
    }
    printf("\n");

    return 0;
}