#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a > b) ? a : b)

BST_Node *newNode(int value) {
    BST_Node *newNode = (BST_Node *)malloc(sizeof(BST_Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BST_Node *insert(BST_Node *root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value <= root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
};

BST_Node *deleteNode(BST_Node *root, int targetVal) {
    if (root == NULL)
        return NULL;

    if (targetVal < root->data)
        root->left = deleteNode(root->left, targetVal);
    else if (targetVal > root->data)
        root->right = deleteNode(root->right, targetVal);
    else {
        // only one child
        if (root->left == NULL) {
            BST_Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BST_Node *temp = root->left;
            free(root);
            return temp;
        }

        // with two children
        BST_Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
};

BST_Node *findMax(BST_Node *root) {
    if (root->right == NULL)
        return root;
    else
        return findMax(root->right);
};

BST_Node *findMin(BST_Node *root) {
    if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
};

bool isEmpty(BST_Node *root) {
    return root == NULL;
};

int height(BST_Node *root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + MAX(leftHeight, rightHeight);
}

void preorder(BST_Node *root) {
    BST_Node *current = root;
    if (current != NULL) {
        printf("%d ", current->data);
        preorder(current->left);
        preorder(current->right);
    }
};

void inorder(BST_Node *root) {
    BST_Node *current = root;
    if (current != NULL) {
        inorder(current->left);
        printf("%d ", current->data);
        inorder(current->right);
    }
};

void postorder(BST_Node *root) {
    BST_Node *current = root;
    if (current != NULL) {
        postorder(current->left);
        postorder(current->right);
        printf("%d ", current->data);
    }
};