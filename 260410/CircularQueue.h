#define MAX_SIZE 100

Element data[MAX_SIZE];
int front;
int rear;

void error(char* str) {
    printf("%s\n", str);
    exit(1);
}

void init_queue(void) {
    front = rear = 0;
}

int is_empty(void) {
    return front == rear;
}

int is_full(void) {
    return front == (rear + 1) % MAX_SIZE;
}

void enqueue(Element val) {
    if (is_full()) {
        error("Overflow Error");
    }
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = val;
}

Element dequeue(void) {
    if (is_empty()) {
        error("Underflow Error");
    }
    front = (front + 1) % MAX_SIZE;
    return data[front];
}

Element peek(void) {
    if (is_empty()) {
        error("Underflow Error");
    }
    return data[(front + 1) % MAX_SIZE];
}