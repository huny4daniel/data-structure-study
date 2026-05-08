typedef struct Node {
    Element data;
    struct Node *link;
} Node;

Node *head = NULL;

void error(char *str) {
    printf("%s\n", str);
    
    exit(1);
}

Node* alloc_node(Element e) {
    Node *p = (Node*)malloc(sizeof(Node));

    if (p == NULL) {
        error("Failed alloc memory");
    }

    p->data = e;
    p->link = NULL;

    return p;
}

Element free_node(Node *p) {
    Element e = p->data;

    free(p);

    return e;
}

int is_empty(void) {
    return head == NULL;
}

int is_full(void) {
    return 0;
}

void init_list(void) {
    head = NULL;
}

Node* get_node(int pos) {
    if (pos < 0) {
        return NULL;
    }

    Node *p = head;
    for (int i = 0; i < pos; i++, p = p->link) {
        if (p == NULL) {
            return NULL;
        }
    }

    return p;
}

Element get_entry(int pos) {
    Node *p = get_node(pos);

    if (p == NULL) {
        error("Invalid position");
    }

    return p->data;
}

void insert(int pos, Element e) {
    Node *p = alloc_node(e);

    if (pos == 0) {
        p->link = head;
        head = p;
    } 
    else {
        Node *before = get_node(pos - 1);
        if (before == NULL) {
            error("Invalid position");
        }

        p->link = before->link;
        before->link = p;
    }
}

Element delete(int pos) {
    if (is_empty()) {
        error("Underflow");
    }

    Node *p = get_node(pos);
    if (p == NULL) {
        error("Invalid position");
    }

    Node *before = get_node(pos - 1);
    if (before == NULL) {
        head = head->link;
    } 
    else {
        before->link = p->link;
    }

    return free_node(p);
}
    
void destroy_list(void) {
    while (is_empty() == 0) {
        delete(0);
    }
}

int size(void) {
    int count = 0;

    for (Node *p = head; p != NULL; p = p->link) {
        count++;
    }

    return count;
}

void append(Element e) {
    insert(size(), e);
}

Element pop(void) {
    return delete(size() - 1);
}

void replace(int pos, Element e) {
    Node *p = get_node(pos);

    if (p == NULL) {
        error("Invalid position");
    }

    p->data = e;
}

int find(Element e) {
    int i = 0;

    for (Node *p = head; p != NULL; p = p->link, i++) {
        if (p->data == e) {
            return i;
        }
    }

    return -1;
}