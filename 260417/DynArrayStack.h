int MAX_SIZE = 10;

Element* data = NULL;
int top;

void error(char str[]) {
    printf("%s\n", str);
    exit(1);
}

int is_empty(void) {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_full(void) {
    return ((top == MAX_SIZE - 1));
}

void init_stack(void) {
    data = (Element*)malloc(sizeof(Element) * MAX_SIZE);
    top = -1;
}

void push(Element e) {
    if (is_full()) {
       MAX_SIZE *= 2;
       data = (Element*)realloc(data, sizeof(Element) * MAX_SIZE);
       printf("realloc(%d)\n", MAX_SIZE);
    }
    data[++top] = e;
}

Element pop(void) {
    if (is_empty()) {
        error("Underflow");
    }
    return data[top--];
}

Element peek(void) {
    if (is_empty()) {
        error("Underflow");
    }
    return data[top];
}