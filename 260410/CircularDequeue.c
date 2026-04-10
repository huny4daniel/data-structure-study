#include <stdio.h>
#include <stdlib.h>

#define Element int

#include "CircularDequeue.h"

void print_deque(char msg[]) {
    printf("%s front=%d, rear=%d -->", msg, front, rear);

    int size = (rear - front + MAX_SIZE) % MAX_SIZE;

    for (int i = front + 1; i <= size + front; i++) {
        printf("%2d ", data[i % MAX_SIZE]);
    }
    printf("\n");
}

int main(void) {
    init_deque();

    for (int i = 1; i < 10; i++) {
        if (i % 2) {
            add_front(i);
        } 
        else {
            add_rear(i);
        }
    }
    print_deque("원형 덱 홀수 - 짝수 ");
    printf("\tdelete_front() --> %d\n", delete_front());
    printf("\tdelete_rear() --> %d\n", delete_rear());
    printf("\tdelete_front() --> %d\n", delete_front());
    print_deque("원형 덱 삭제 - 홀짝홀 ");
}