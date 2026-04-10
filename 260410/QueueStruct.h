#define MAX_SIZE 100

typedef struct Queue {
    Element data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void error(char* str) {
    printf("%s\n", str);
    exit(1);
}

void init_queue(Queue *q) {
    q->front = q->rear = 0;
}

int is_empty(Queue *q) {
    return q->front == q->rear;
}

int is_full(Queue *q) {
    return q->front == (q->rear + 1) % MAX_SIZE;
}

void enqueue(Queue *q, Element val) {
    if (is_full(q)) {
        error("Overflow Error");
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = val;
}

Element dequeue(Queue *q) {
    if (is_empty(q)) {
        error("Underflow Error");
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

Element peek(Queue *q) {
    if (is_empty(q)) {
        error("Underflow Error");
    }
    return q->data[(q->front + 1) % MAX_SIZE];
}

int size (Queue *q) {
    return (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}