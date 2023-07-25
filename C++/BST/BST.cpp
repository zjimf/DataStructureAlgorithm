#include "BST.h"
#include <algorithm>
#include <iostream>
using namespace std;

Node::Node(int data) : data(data), left(nullptr), right(nullptr){};
BST::BST() : root(nullptr){};

Node *BST::getRoot() {
    return root;
}

Node *BST::newNode(int value) {
    Node *newNode = new Node(value);
    return newNode;
}

Node *BST::insert(Node *&root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value <= root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

Node *BST::deleteNode(Node *root, int targetVal) {
    if (root == nullptr)
        return nullptr;

    if (targetVal < root->data)
        root->left = deleteNode(root->left, targetVal);
    else if (targetVal > root->data)
        root->right = deleteNode(root->right, targetVal);
    else {
        // one child
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // children
        Node *temp = root;
        // find min node
        while (temp->left != nullptr)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int BST::findMax(Node *root) {
    if (root->right == NULL)
        return root->data;
    else
        return findMax(root->right);
}

int BST::findMin(Node *root) {
    if (root->left == NULL)
        return root->data;
    else
        return findMin(root->left);
}

bool BST::isEmpty() {
    return root == nullptr;
}

int BST::height(Node *root) {
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void BST::preorder(Node *root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void BST::inorder(Node *root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void BST::postorder(Node *root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
