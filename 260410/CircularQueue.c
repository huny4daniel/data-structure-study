#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "CircularQueue.h"

void print_queue(char msg[]) {
    printf("%s front=%d, rear=%d -->", msg, front, rear);

    int size = (rear - front + MAX_SIZE) % MAX_SIZE;

    for (int i = front + 1; i <= size + front; i++) {
        printf("%2d ", data[i % MAX_SIZE]);
    }
    printf("\n");
}

void main(void) {
    init_queue();

    for (int i = 1; i < 7; i++) {
        enqueue(i);
    }
    print_queue("enqueue 1 ~ 6");
    
    for (int i = 0; i < 4; i++) {
        dequeue();
    } 
    print_queue("dequeue 4회:");

    for (int i = 7; i < 10; i++) {
        enqueue(i);
    } 
    print_queue("enqueue 7 ~ 10");
}