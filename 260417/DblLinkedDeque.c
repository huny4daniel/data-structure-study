#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "DblLinkedDeque.h"

void print_deque(char *msg) {
    printf("%s= ", msg);

    if (rear != NULL) {
        for (Node *p = rear->rlink; p != rear; p = p->rlink) {
            printf("%2d ", p->data);
        }
        printf("%2d ", rear->data);
    }

    printf("\n");
}

int main(void) {
    init_deque();

    for (int i = 1; i <= 6; i++) {
        add_rear(i);
    }
    print_deque("add_rear 1~6 ");

    add_front(0);
    print_deque("add_front 0  ");

    printf("delete_front: %d\n", delete_front());
    printf("delete_rear:  %d\n", delete_rear());
    print_deque("삭제 후      ");

    destroy_deque();
}
