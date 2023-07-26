#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int height(Node *node) {
    return node == NULL ? 0 : node->height;
}

Node *newNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    newNode->height = 1;
    return newNode;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = MAX(height(y->left), height(y->right)) + 1;
    x->height = MAX(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *y) {
    Node *x = y->right;
    Node *t = x->left;

    x->left = y;
    y->right = t;

    y->height = MAX(height(y->left), height(y->right)) + 1;
    x->height = MAX(height(x->left), height(x->right)) + 1;

    return x;
}

int getBalance(Node *node) {
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

Node *insert(Node *node, int data) {
    if (node == NULL)
        return newNode(data);
    if (data <= node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    node->height = 1 + MAX(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    // LL
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // RR
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // LR
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *minValue(Node *node) {
    struct Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *delete(Node *node, int target) {
    if (node == NULL)
        return node;

    if (target < node->data)
        node->left = delete (node->left, target);
    else if (target > node->data)
        node->right = delete (node->right, target);
    else {
        if (node->left == NULL || node->right == NULL) {
            Node *temp = node->left ? node->left : node->right;

            // no child
            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else // one child
                *node = *temp;

            free(temp);
        } else { // two children find minimum to replace
            struct Node *temp = minValue(node->right);
            node->data = temp->data;
            node->right = delete (node->right, temp->data);
        }
    }

    if (node == NULL)
        return node;

    node->height = 1 + MAX(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preorder(Node *root) {
    Node *current = root;
    if (current != NULL) {
        printf("%d ", current->data);
        preorder(current->left);
        preorder(current->right);
    }
}

void inorder(Node *root) {
    Node *current = root;
    if (current != NULL) {
        inorder(current->left);
        printf("%d ", current->data);
        inorder(current->right);
    }
}

void postorder(Node *root) {
    Node *current = root;
    if (current != NULL) {
        postorder(current->left);
        postorder(current->right);
        printf("%d ", current->data);
    }
}