#include "AVL.h"
#include <stdio.h>

int main() {
    struct Node *root = NULL;
    int data[] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
    int len = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < len; i++) {
        root = insert(root, data[i]);
    }

    printf("inorder: ");
    inorder(root);
    printf("\n");

    root = delete (root, 10);

    printf("inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}