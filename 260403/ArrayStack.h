#define MAX_SIZE 100

Element data[MAX_SIZE];

int is_full(void);

int top;

void error (char str[]) {
    printf("%s\n", str);

    exit(1);
}

void init_stack() {
    top = -1;
}

int is_empty() {
    if (top == -1) {
        return 1;
    } 
    else {
        return 0;
    }
}

void push(Element e) {
    if (is_full()) {
        error ("Overflow Error!");
    }
    else {
        data[++top] = e;
    }
}

int is_full() {
    return (top == (MAX_SIZE - 1));
}

Element pop(void) {
    if (is_empty()) {
        error ("Underflow Error!");
    }
    else {
        return (data[top--]);
    }
}

Element peek(void) {
    if (is_empty()) {
        error ("Underflow Error!");
    }
    else {
        return (data[top]);
    }
}

int size(void) {
    return (top + 1);
}