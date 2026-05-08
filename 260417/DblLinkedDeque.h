typedef struct Node {
    Element data;
    struct Node* llink;
    struct Node* rlink;
} Node;

Node *rear = NULL;

Node* alloc_node(Element e) {
    Node *p = (Node*)malloc(sizeof(Node));

    p->data = e;
    p->llink = NULL;
    p->rlink = NULL;

    return p;
}

Element free_node(Node *p) {
    Element e = p->data;

    free(p);

    return e;
}

void error(char *str) {
    printf("%s\n", str);

    exit(1);
}

int is_empty(void) {
    return (rear == NULL);
}

int is_full(void) {
    return 0;
}

void init_deque(void) {
    rear = NULL;
}

void add_rear(Element e) {
    Node *p = alloc_node(e);

    if (is_empty()) {
        rear = p;
        p->llink = p;
        p->rlink = p;
    }
    else {
        Node *front = rear->rlink;
        p->rlink = front;
        p->llink = rear;
        rear->rlink = p;
        front->llink = p;
        rear = p;
    }
}

void add_front(Element e) {
    Node *p = alloc_node(e);

    if (is_empty()) {
        rear = p;
        p->llink = p;
        p->rlink = p;
    }
    else {
        Node *front = rear->rlink;
        p->rlink = front;
        p->llink = rear;
        rear->rlink = p;
        front->llink = p;
    }
}

Element delete_front(void) {
    if (is_empty()) {
        error("Underflow Error!");
    }

    Node *front = rear->rlink;

    if (rear == front) {
        rear = NULL;
    }
    else {
        rear->rlink = front->rlink;
        front->rlink->llink = rear;
    }

    return free_node(front);
}

Element delete_rear(void) {
    if (is_empty()) {
        error("Underflow Error!");
    }

    Node *p = rear;

    if (rear == rear->rlink) {
        rear = NULL;
    }
    else {
        Node *new_rear = rear->llink;
        new_rear->rlink = rear->rlink;
        rear->rlink->llink = new_rear;
        rear = new_rear;
    }

    return free_node(p);
}

Element peek_front(void) {
    if (is_empty()) {
        error("Underflow Error!");
    }

    return rear->rlink->data;
}

Element peek_rear(void) {
    if (is_empty()) {
        error("Underflow Error!");
    }

    return rear->data;
}

void destroy_deque(void) {
    while (is_empty() == 0) {
        delete_front();
    }
}

int size(void) {
    if (is_empty()) {
        return 0;
    }

    int count = 1;

    for (Node *p = rear->rlink; p != rear; p = p->rlink) {
        count++;
    }

    return count;
}
