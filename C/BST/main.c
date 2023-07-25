#include "BST.h"
#include <stdio.h>

int main() {
    BST_Node *root = NULL;
    int data[] = {10, 50, 20, 30, 40, 5, 45};
    int len = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < len; i++) {
        if (i == 0)
            root = insert(root, data[i]);
        else
            insert(root, data[i]);
    }

    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    BST_Node *Max = findMax(root);
    printf("Max value in BST: %d\n", Max->data);
    BST_Node *Min = findMin(root);
    printf("Min value in BST: %d\n", Min->data);

    printf("Delete 30 in BST \n");
    deleteNode(root, 30);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("BST current height: %d\n", height(root));
}