#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "DynArrayStack.h"

int main(void) {
    MAX_SIZE = 8;

    init_stack();

    printf("[입력]\n");

    for (int i = 0; i < 50; i++) {
        printf(" %d", i);
        push(i);
    }
    printf("\n[출력]\n");

    while (!is_empty()) {
        printf(" %d", pop());
    }
    printf("\n");
    free(data);
}