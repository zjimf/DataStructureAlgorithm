#include "BST.h"
#include <iostream>
using namespace std;

int main() {
    BST *bst = new BST();
    Node *root = bst->getRoot();
    int data[] = {10, 50, 20, 30, 40, 5, 45};
    int len = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < len; i++) {
        if (i == 0)
            root = bst->insert(root, data[i]);
        else
            bst->insert(root, data[i]);
    }

    cout << "Inorder: ";
    bst->inorder(root);
    cout << endl;
    cout << "Preorder: ";
    bst->preorder(root);
    cout << endl;
    cout << "Postorder: ";
    bst->postorder(root);
    cout << endl;
    int Max = bst->findMax(root);
    cout << "Max value in BST: " << Max << endl;
    int Min = bst->findMin(root);
    cout << "Min value in BST: " << Min << endl;

    cout << "Delete 30 in BST" << endl;
    bst->deleteNode(root, 30);

    cout << "Inorder: ";
    bst->inorder(root);
    cout << endl;

    cout << "BST current height:" << bst->height(root) << endl;
}