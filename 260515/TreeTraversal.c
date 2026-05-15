#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct TNode {
    TElement data;
    struct TNode *left;
    struct TNode *right;
} TNode;

#define VisitNode(n)( printf("[%c] ", (n)->data))

void preorder(TNode *n) {
    if (n != NULL) {
        VisitNode(n);
        preorder(n->left);
        preorder(n->right);
    }
}

void inorder(TNode *n) {
    if (n != NULL) {
        inorder(n->left);
        VisitNode(n);
        inorder(n->right);
    }
}

void postorder(TNode *n) {
    if (n != NULL) {
        postorder(n->left);
        postorder(n->right);
        VisitNode(n);
    }
}

int main(void) {
    TNode d = {'D', NULL, NULL};
    TNode e = {'E', NULL, NULL};
    TNode b = {'B', &d, &e};
    TNode f = {'F', NULL, NULL};
    TNode c = {'C', &f, NULL};
    TNode a = {'A', &b, &c};
    TNode *root = &a;

    printf("\n In-Order: ");
    inorder(root);
    printf("\n Pre-Order: ");
    preorder(root);
    printf("\n Post-Order: ");  

    
    postorder(root);

    return 0;
}