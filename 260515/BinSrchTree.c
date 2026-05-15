#include <stdio.h>
#include <stdlib.h>

#define KEY(n) (n->data)
#define VisitNode(n)(printf("[%d] ", (n)->data))

typedef int TElement;
typedef struct TNode {
    TElement data;
    struct TNode *left;
    struct TNode *right;
} TNode;

TNode * create_tree(TElement data, TNode *left, TNode *right) {
    TNode *n = (TNode *)malloc(sizeof(TNode));
    n->data = data;
    n->left = left;
    n->right = right;

    return n;
}

void delete_tree(TNode *n) {
    if (n != NULL) {
        delete_tree(n->left);
        delete_tree(n->right);
        free(n);
    }
}

TNode * search_bst(TNode *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key == KEY(root)) {
        return root;
    } else if (key < KEY(root)) {
        return search_bst(root->left, key);
    } else {
        return search_bst(root->right, key);
    }
}

void insert_bst(TNode *root, TNode *n) {
    if (KEY(n) < KEY(root)) {
        if (root->left == NULL) {
            root->left = n;
        } 
        else {
            insert_bst(root->left, n);
        }
    } 
    else if (KEY(n) > KEY(root)) {
        if (root->right == NULL) {
            root->right = n;
        } 
        else {
            insert_bst(root->right, n);
        }
    }
    else {
        free(n);
    }
}

TNode *delete_bst(TNode *root, int key) {
    TNode *n = root;
    TNode *parent = NULL;

    while (n != NULL && key != KEY(n)) {
        parent = n;
        n = (key < KEY(n)) ? n->left : n->right;
    }

    if (n == NULL) {
        return root;
    }

    if ((n->left == NULL && n->right == NULL)) {
        if (parent == NULL) {
            root = NULL;
        } 
        else {
            if (parent->left == n) {
                parent->left = NULL;
            } 
            else {
                parent->right = NULL;
            }
        }
        free(n);
    }
    else if (n->left == NULL || n->right == NULL) {
        TNode *child = (n->left != NULL) ? n->left : n->right;

        if (n == root) {
            root = child;
        } 
        else {
            if (parent->left == n) {
                parent->left = child;
            } 
            else {
                parent->right = child;
            }
        }
        free(n);
    }
    else {
        TNode *succ = n->right;

        while (succ->left != NULL) {
            succ = succ->left;
        }
        n->data = succ->data;
        n->right = delete_bst(n->right, KEY(succ));
    }
    return root;
}

void preorder(TNode *n) {
    if (n != NULL) {
        VisitNode(n);
        preorder(n->left);
        preorder(n->right);
    }
}

int main(void) {
    int keys[] = {35, 18, 7, 26, 12, 3, 68, 22, 30, 99};

    TNode *root = create_tree(keys[0], NULL, NULL);

    for (int i = 1; i < 10; i++) {
        TNode *n = create_tree(keys[i], NULL, NULL);
        insert_bst(root, n);
        printf("\n 삽입 %2d: ", keys[i]);
        preorder(root);
    }

    printf("\n");

    TNode *n = search_bst(root, 26);
    printf("26 탐색: %s\n", (n != NULL) ? "성공" : "실패");

    n = search_bst(root, 25);
    printf("25 탐색: %s\n", (n != NULL) ? "성공" : "실패");

    root = delete_bst(root, 3);
    printf("\n case1: <3> 삭제: ");
    preorder(root);

    root = delete_bst(root, 68);
    printf("\n case2: <68> 삭제: ");
    preorder(root);

    root = delete_bst(root, 18);
    printf("\n case3: <18> 삭제: ");
    preorder(root);

    root = delete_bst(root, 35);
    printf("\n case3: <35> 삭제: ");
    preorder(root);
}