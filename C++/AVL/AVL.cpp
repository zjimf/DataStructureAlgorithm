#include "AVL.h"
#include <iostream>
#include <math.h>
using namespace std;

Node::Node(int data) : left(nullptr), right(nullptr), height(1), data(data){};
AVL::AVL() : root(nullptr){};

Node *AVL::getRoot() {
    return root;
}

int AVL::height(Node *node) {
    if (node == nullptr)
        return 0;
    return 1 + max(height(node->left), height(node->right));
};

Node *AVL::newNode(int data) {
    Node *newNode = new Node(data);
    return newNode;
}

Node *AVL::rightRotate(Node *y) {
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    x->height = max(height(x->right), height(x->left)) + 1;
    y->height = max(height(y->right), height(y->left)) + 1;

    return x;
}

Node *AVL::leftRotate(Node *y) {
    Node *x = y->right;
    Node *t = x->left;

    x->left = y;
    y->right = t;

    x->height = max(height(x->right), height(x->left)) + 1;
    y->height = max(height(y->right), height(y->left)) + 1;

    return x;
}

int AVL::getBalance(Node *node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node *AVL::minValue(Node *node) {
    Node *current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node *AVL::insert(Node *node, int data) {
    if (node == nullptr)
        return newNode(data);
    if (data <= node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node->left);

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

Node *AVL::deleteNode(Node *node, int target) {
    if (node == NULL)
        return node;

    if (target < node->data)
        node->left = deleteNode(node->left, target);
    else if (target > node->data)
        node->right = deleteNode(node->right, target);
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
            node->right = deleteNode(node->right, temp->data);
        }
    }

    if (node == NULL)
        return node;

    node->height = 1 + max(height(node->left),
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

void AVL::preorder(Node *root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void AVL::inorder(Node *root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void AVL::postorder(Node *root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}