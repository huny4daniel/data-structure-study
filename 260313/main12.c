#include <stdio.h>

int main() {
    typedef struct Node {
        int data;
        struct Node *next;
    } Node;

    Node n3= {30, NULL};
    Node n2 = {20, &n3};
    Node n1 = {10, &n2};

    return 0;
}